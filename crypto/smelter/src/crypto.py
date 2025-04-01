from Crypto.Util.number import getPrime, bytes_to_long, long_to_bytes
from Crypto.PublicKey import RSA

from hashlib import sha256
from util import encode, decode

e = 3
p, q = getPrime(1024), getPrime(1024)
while True:
    n = p * q
    phi = (p - 1) * (q - 1)
    try:
        d = pow(e, -1, phi)
        break
    except:
        p, q = getPrime(1024), getPrime(1024)

privkey = RSA.construct((n, e, d))
pubkey = privkey.publickey()

def public_key() -> str:
    return pubkey.export_key(format='PEM').decode()

def sign(message: bytes) -> bytes:
    h = sha256(message).digest()
    h = encode(h)
    return long_to_bytes(pow(bytes_to_long(h), d, n))

def verify(message: bytes, signature: bytes) -> bool:
    h = sha256(message).digest()

    signature = bytes_to_long(signature)
    signature = pow(signature, e, n)
    signature = long_to_bytes(signature, 256)

    signed_h = decode(signature)
    return h == signed_h