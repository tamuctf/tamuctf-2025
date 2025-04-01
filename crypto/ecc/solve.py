from Crypto.Util.number import bytes_to_long, long_to_bytes
from ecdsa.ecdsa import generator_256
from hashlib import sha256

def inverse_mod(a, m):
    return pow(a, -1, m)

generator = generator_256
n = generator.order()

message1 = "The secp256r1 curve was used."
message2 = "k value may have been re-used."

message1 = bytes_to_long(sha256(message1.encode()).digest())
message2 = bytes_to_long(sha256(message2.encode()).digest())

k = (message1 - message2) * inverse_mod(8734396013686485452502025686012376394264288962663555711176194873788392352477 \
 - 96254287552668750588265978919231985627964457792323178870952715849103024292631, n) % n
key = inverse_mod(91684750294663587590699225454580710947373104789074350179443937301009206290695, n) \
* (k * 8734396013686485452502025686012376394264288962663555711176194873788392352477 - message1) % n

print(long_to_bytes(key).decode())