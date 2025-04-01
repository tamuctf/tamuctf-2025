from Crypto.Util.number import bytes_to_long, long_to_bytes
from hashlib import sha256
from secret import sign

message1 = "The secp256r1 curve was used."
message2 = "k value may have been re-used."

message1 = bytes_to_long(sha256(message1.encode()).digest())
message2 = bytes_to_long(sha256(message2.encode()).digest())

r1, s1 = sign(message1)
r2, s2 = sign(message2)

print(f"r1: {r1}, s1: {s1}")
print(f"r2: {r2}, s2: {s2}")