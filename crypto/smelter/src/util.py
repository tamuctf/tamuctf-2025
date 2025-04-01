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