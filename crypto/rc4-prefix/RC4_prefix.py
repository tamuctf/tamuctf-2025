from Crypto.Cipher import ARC4
import os
from string import printable
from random import choices

IV = ''.join(choices(printable,k=32)).encode()
for i in range(96):
    nonce = input("Give me a prefix (hex): ")
    try:
        nonce = bytes.fromhex(nonce)
    except:
        print("Make sure to send in hex.")
        exit()
    if len(nonce) + len(IV) > 256:
        print("Your prefix is too long.")
        exit()
    try:
        cipher = ARC4.new(nonce + IV)
    except:
        print("Could not create the cipher.")
        exit()
    
    pt = b"\0"
    ct = cipher.encrypt(pt)
    print(f"Your lucky number is {ord(ct)}")

guess = input("What was the IV(hex): ")
try:
    guess = bytes.fromhex(guess)
except:
    print("Make sure to send your guess for the IV in hex.")
    exit()
if IV == guess:
    with open("flag.txt","r") as f:
        FLAG = f.read()
        print(FLAG)
else:
    print(f"WRONG! IV was {IV.hex()}")
