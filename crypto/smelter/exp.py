from Crypto.Util.number import bytes_to_long, long_to_bytes
from hashlib import sha256
from gmpy2 import iroot
import requests
import json
import base64

from pyasn1.codec.der import encoder, decoder
from pyasn1.type import univ, namedtype


class AlgorithmIdentifier(univ.Sequence):
    componentType = namedtype.NamedTypes(
        namedtype.NamedType('algorithm', univ.ObjectIdentifier()),
        namedtype.NamedType('parameters', univ.Null())
    )

class DigestInfo(univ.Sequence):
    componentType = namedtype.NamedTypes(
        namedtype.NamedType('digestAlgorithm', AlgorithmIdentifier()),
        namedtype.NamedType('digest', univ.OctetString())
    )

# we only use sha256 so no need to worry about other algorithms
SHA256_OID = (2, 16, 840, 1, 101, 3, 4, 2, 1)
SHA256_ALGORITHM = AlgorithmIdentifier()
SHA256_ALGORITHM['algorithm'] = SHA256_OID
SHA256_ALGORITHM['parameters'] = univ.Null()

def encode(hash):
    obj = DigestInfo()
    obj['digestAlgorithm'] = SHA256_ALGORITHM
    obj['digest'] = hash
    enc = encoder.encode(obj)
    padding_len = 256 - len(enc) - 3
    if padding_len < 0:
        raise Exception("hash too long")
    return b"\x00\x01" + b"\xff" * (256 - len(enc) - 3) + b"\x00" + enc

def decode(data):
    try:
        data = data[3:]
        data = data[data.index(b"\x00") + 1:]
        obj, _ = decoder.decode(data, asn1Spec=DigestInfo())
        assert obj['digestAlgorithm']['algorithm'].asTuple() == SHA256_OID
        assert isinstance(obj['digestAlgorithm']['parameters'], univ.Null)
        assert isinstance(obj['digest'], univ.OctetString)

        return obj['digest'].asOctets()
    except:
        # clearly you don't have a real signature
        return None

e = 3
# Forge a signature for the message "admin"
forged_message = b"admin"
hash_forged_message = sha256(forged_message).digest()
encoded_forged_hash = encode(hash_forged_message)

encoded_forged_inner = encoded_forged_hash[3:]
encoded_forged_inner = encoded_forged_inner[encoded_forged_inner.index(b"\x00") + 1:]

encoded_forged = b"\x00\x01\xff\x00" + encoded_forged_inner + b"\xff" * (256 - len(encoded_forged_inner) - 4)

print(f"Encoded forged hash: {encoded_forged}")

# Since e = 3, we can take the cube root of the encoded hash to forge the signature
forged_signature_int = bytes_to_long(encoded_forged) 
forged_signature_int = int(iroot(forged_signature_int, e)[0])
forged_signature = long_to_bytes(forged_signature_int)

print(bytes_to_long(forged_signature).bit_length())

data = {
    "signature": base64.b64encode(forged_signature).decode(),
    "username": "admin"
}
smelter_session = base64.b64encode(json.dumps(data).encode()).decode()
print(f"Forged session: {smelter_session}")

s = requests.Session()
s.cookies["smelter-session"] = smelter_session
r = s.get("http://localhost:5000/")
print(r.text)