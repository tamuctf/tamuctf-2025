# ECC

Author: `Monk`

Can you get the secret key from the following two signed messages?

1st Message: "The secp256r1 curve was used."
2nd Message: "k value may have been re-used." 

1st Signature r value: `91684750294663587590699225454580710947373104789074350179443937301009206290695`
1st Signature s value: `8734396013686485452502025686012376394264288962663555711176194873788392352477`

2nd Signature r value: `91684750294663587590699225454580710947373104789074350179443937301009206290695`
2nd Signature s value: `96254287552668750588265978919231985627964457792323178870952715849103024292631`

## Solution

The messages imply a nonce-reuse attack. Additionally, since the two signatures have the same `r` value, we can assume they must also have used the same `k` value.

Then, when the `s` value is calculated as `s = (h + r*key) / k`, since we have two messages, we can first solve for `k`, then use that to solve for the private key.
```python
from Crypto.Util.number import bytes_to_long, long_to_bytes
from ecdsa.ecdsa import generator_256 as G
from hashlib import sha256
n = G.order()

r1 = 91684750294663587590699225454580710947373104789074350179443937301009206290695
s1 = 8734396013686485452502025686012376394264288962663555711176194873788392352477

r2 = 91684750294663587590699225454580710947373104789074350179443937301009206290695
s2 = 96254287552668750588265978919231985627964457792323178870952715849103024292631

message1 = bytes_to_long(sha256("The secp256r1 curve was used.".encode()).digest())
message2 = bytes_to_long(sha256("k value may have been re-used.".encode()).digest())

# (m1 + r * key) / k = s1
# (m2 + r * key) / k = s2
# (m1 - m2) / k = (s1 - s2)
# k = (m1 - m2) / (s1 - s2)
k = (message1 - message2) * pow(s1 - s2, -1, n) % n
print(k)

# (m1 + r * key) / k = s1
# r * key = k * s1 - m1
# key = (k * s1 - m1) / r
key = (k * s1 - message1) * pow(r1, -1, n) % n
print(long_to_bytes(key).decode())
```

flag:
`gigem{r3u51n6_k_0n_516n47ur35}`