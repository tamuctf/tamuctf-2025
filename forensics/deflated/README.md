# Deflated

Author: `flocto`

I heard [ZipCrypto Store has a vulnerability](https://github.com/kimci86/bkcrack), so I've used ZipCrypto Deflate instead. Can you still get the flag?

Notes
- Flag matches regex `gigem{[A-Z0-9_]+}`.
- Do not try to brute force the password. It is not in any password list.

## Dev Notes

To zip the files, simply run the following in the `src/` directory:
```
zip -e -r -1 deflated.zip print_flag.py .git/*
```
Then paste in the contents of password.txt twice.

I couldn't figure out how to make the password non-interactive so we'll just have to use the already zipped file for now. It's small enough anyway that it shouldn't be a problem.

Also for test solve please do not use password.txt lol.

Also also just as a hint you don't need to figure out how to use bkcrack with deflate ;)

## Solution

With bkcrack we can see that even though most of the ZipCrypto files are stored with Deflate, there are several smaller files still stored with Store:

```
bkcrack 1.7.0 - 2024-05-26
Archive: deflated.zip
Index Encryption Compression CRC32    Uncompressed  Packed size Name
----- ---------- ----------- -------- ------------ ------------ ----------------
    0 ZipCrypto  Deflate     fcd92ad5          500          149 print_flag.py
    1 ZipCrypto  Deflate     967f1426           75           74 .git/COMMIT_EDITMSG
    2 ZipCrypto  Store       576463b5           21           33 .git/HEAD
    3 None       Store       00000000            0            0 .git/branches/
    4 ZipCrypto  Deflate     bb5adcd1          112          102 .git/config
    5 ZipCrypto  Deflate     1f078b37           73           75 .git/description
    6 ZipCrypto  Deflate     d21224f8          145          146 .git/index
    7 None       Store       00000000            0            0 .git/info/
    8 ZipCrypto  Deflate     21cd3d77          240          185 .git/info/exclude
    9 None       Store       00000000            0            0 .git/logs/
   10 ZipCrypto  Deflate     c5d70e9f          364          203 .git/logs/HEAD
   11 None       Store       00000000            0            0 .git/logs/refs/
   12 None       Store       00000000            0            0 .git/logs/refs/heads/
   13 ZipCrypto  Deflate     c5d70e9f          364          203 .git/logs/refs/heads/main
   14 None       Store       00000000            0            0 .git/objects/
   15 None       Store       00000000            0            0 .git/objects/01/
   16 ZipCrypto  Store       3bf59ff7          119          131 .git/objects/01/c525a1a206c1a6dd2f4124b19c60853e16ff3c
   17 None       Store       00000000            0            0 .git/objects/20/
   18 ZipCrypto  Store       047fb968          266          278 .git/objects/20/e03717d7ede63e8c344e97e3451559213844e0
   19 None       Store       00000000            0            0 .git/objects/43/
   20 ZipCrypto  Store       2ad0c039           57           69 .git/objects/43/5e8f8c19faa69d279d18f3862209380fbd710f
   21 None       Store       00000000            0            0 .git/objects/5e/
   22 ZipCrypto  Store       caab86cf          190          202 .git/objects/5e/6304a711c542fb448a368be9270c7aba3ba627
   23 None       Store       00000000            0            0 .git/objects/7d/
   24 ZipCrypto  Store       13d90929           58           70 .git/objects/7d/7cda2c8ffed4caf0f92f956eb2372e7bbd4ed5
   25 None       Store       00000000            0            0 .git/objects/8f/
   26 ZipCrypto  Store       3b720017          155          167 .git/objects/8f/9acad28f3184c2124935c0f55422386d696f6a
   27 None       Store       00000000            0            0 .git/objects/info/
   28 None       Store       00000000            0            0 .git/objects/pack/
   29 None       Store       00000000            0            0 .git/refs/
   30 None       Store       00000000            0            0 .git/refs/heads/
   31 ZipCrypto  Store       efd9b0df           41           53 .git/refs/heads/main
   32 None       Store       00000000            0            0 .git/refs/tags/
```

In particular, `.git/refs/heads/main` is 41 bytes long. This corresponds to the 40 hex characters of the tracked commit hash at main, followed by a newline. 

Additionally, since the commit hash has to be stored in the object databasem we can brute force all the possible hashes and try to use them in bkcrack

```
01c525a1a206c1a6dd2f4124b19c60853e16ff3c
20e03717d7ede63e8c344e97e3451559213844e0
435e8f8c19faa69d279d18f3862209380fbd710f
5e6304a711c542fb448a368be9270c7aba3ba627
7d7cda2c8ffed4caf0f92f956eb2372e7bbd4ed5
8f9acad28f3184c2124935c0f55422386d696f6a
```

Eventually we find that `5e6304a711c542fb448a368be9270c7aba3ba627` works with bkcrack and gives us usable keys.

```
$  ~/tools/bkcrack-1.7.0-Linux/bkcrack -C ../deflated.zip -c .git/refs/heads/main -p plaintext.bin 
bkcrack 1.7.0 - 2024-05-26
[22:02:08] Z reduction using 34 bytes of known plaintext
100.0 % (34 / 34)
[22:02:08] Attack on 225410 Z values at index 6
Keys: f2635bca a91bec3a ec81bdf9
2.3 % (5232 / 225410)
Found a solution. Stopping.
You may resume the attack with the option: --continue-attack 5232
[22:02:11] Keys
f2635bca a91bec3a ec81bdf9
```

Then, we can simply create a new zip file with no password and extract the contents:
```
$ ~/tools/bkcrack-1.7.0-Linux/bkcrack -C ../deflated.zip -k f2635bca a91bec3a ec81bdf9 -D deflated_no_password.zip
bkcrack 1.7.0 - 2024-05-26
[22:06:45] Writing decrypted archive ../deflated_no_password.zip
100.0 % (16 / 16)

$ unzip deflated_no_password.zip
Archive:  deflated_no_password.zip
  inflating: print_flag.py     
  ...
```

From here, we simply need to revert to the previous git commit and run the Python script to get the flag.

```
$ git log
commit 5e6304a711c542fb448a368be9270c7aba3ba627 (HEAD -> main)
Author: flocto <flocto@duck.com>
Date:   Mon Mar 17 15:14:50 2025 -0500

    remove flag and put a super long commit message so that it gets compressed

commit 01c525a1a206c1a6dd2f4124b19c60853e16ff3c
Author: flocto <flocto@duck.com>
Date:   Mon Mar 17 15:14:13 2025 -0500

    initial commit

$ git reset --hard 01c525a1a206c1a6dd2f4124b19c60853e16ff3c
HEAD is now at 01c525a initial commit

$ python3 print_flag.py
                            ___                                                                                                                                   ___   
      _                    |  _|____   _____  _____  _____       _____  _____  _____  __          ___       ____   _____  _____  __     _____  _____  _____  ____|_  |  
 ___ |_| ___  ___  _____  _| | |    \ |     ||   | ||_   _|     |   __||   __||   __||  |        |_  |     |    \ |   __||   __||  |   |  _  ||_   _||   __||    \ | |_ 
| . || || . || -_||     ||_  | |  |  ||  |  || | | |  | |       |   __||   __||   __||  |__      |  _|     |  |  ||   __||   __||  |__ |     |  | |  |   __||  |  ||  _|
|_  ||_||_  ||___||_|_|_|  | |_|____/ |_____||_|___|  |_|  _____|__|   |_____||_____||_____|_____|___|_____|____/ |_____||__|   |_____||__|__|  |_|  |_____||____/_| |  
|___|   |___|              |___|                          |_____|                          |_____|   |_____|                                                     |___|  
```

flag:
`gigem{DONT_FEEL_2_DEFLATED}`
