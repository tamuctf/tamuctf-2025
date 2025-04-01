from Crypto.Util.number import bytes_to_long
from ecdsa.ecdsa import generator_256 as G
n = G.order()
priv_key = bytes_to_long(b"gigem{r3u51n6_k_0n_516n47ur35}")

def inverse_mod(a, m):
    return pow(a, -1, m)

def sign(message):
    k = 52645124711413831884690619897734762769666181260317026191225734697419928743830

    r = G * k
    r = r.x() % n

    s = inverse_mod(k, n) * (message + r * priv_key) % n

    return r, s