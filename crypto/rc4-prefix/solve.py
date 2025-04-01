from collections import Counter
import os
from pwn import *
from string import printable

length = 256 - 32
# context.log_level = 'debug'

def get_response(p,nonce):
    """Send a request to the server and check if the response is 'Pong!'"""
    
    p.sendlineafter(b"Give me a prefix (hex): ",nonce.hex().encode())
    resp = int(p.recvline().split()[-1])
    return resp.to_bytes(1,'big')

def recover_keystream(p,length = length,nonce = None):
    if nonce is None:
        nonce = b"\0"*length
    return [c for c in get_response(p,nonce)]

def get_first_char(prefix,suffix = b""):
    key = prefix + suffix
    S = [i for i in range(256)]
    j = 0
    for i in range(len(key)):
        j = (j + S[i] + key[i % len(key)]) % 256
        S[i],S[j] = S[j],S[i]
    t = (S[S[1]] + S[1]) % 256
    return t,S[t]

def get_n_value(prefix,suffix,n):
    key = prefix + suffix
    S = [i for i in range(256)]
    j = 0
    for i in range(len(key)):
        j = (j + S[i] + key[i % len(key)]) % 256
        S[i],S[j] = S[j],S[i]
    return S[n]

total = 0
inc = 0
trials = 96
tries = 20
ncount = 0
for i in range(tries):
    p = remote("localhost",1337)
    # p = process(["python3","RC4_prefix.py"])
    
    IV = b""

    count = 0
    counts = Counter()
    times = 0
    while len(IV) + length != 256 and count < trials:
        times += 1
        t = 0
        while t != length + len(IV):
            prefix = os.urandom(length)
            t,K = get_first_char(prefix,IV)

        if t == length + len(IV):
            count += 1
            correct = recover_keystream(p,length,prefix)[0]
            
            for c in printable:
                c = c.encode()
                ans = get_n_value(prefix,IV + c,t)
                if correct == ans:
                    counts[c.decode()] += 1

        
        valid = []
        if times > 1:
            if len(counts) > 0:
                maxval = max(counts.values())
                for c in counts:
                    # majority vote
                    if counts[c] >= (maxval+1) // 2:
                        valid.append(c)
                
                if len(valid) == 1:
                    counts = Counter()
                    found = True
                    IV += valid[0].encode()
                    times = 0
            else:
                # backtrack
                IV = IV[:-1]
                times = 0
    
    if count < trials:
        p.send(b"00\n"*(trials-count))
        
    ncount += count
    p.sendlineafter(b"What was the IV(hex): ",IV.hex().encode())
    result = p.recvline()
    p.close()
    if b"WRONG" not in result:
        print(count, result)
        total += 1
print(total / tries)
print(ncount / tries)