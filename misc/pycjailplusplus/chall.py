#!/usr/local/bin/python3.12
import opcode
cod = bytes.fromhex(input("code? "))
name = input("name? ")
const = input("const? ")

if len(cod) > 100 or len(cod) % 2 != 0 or len(name) > 25 or len(const) > 25:
    print("your code looks bad :(")
    exit(1)

# can't hack me if I just ban every opcode
banned = set(opcode.opmap.values())
for i in range(0, len(cod), 2):
    [op, arg] = cod[i:i + 2]
    if op in banned:
        print("your code is sus >:(")
        exit(1)
    if arg > 64:
        print("I can't count that high >:(")
        exit(1)


def f():
    pass

f.__code__ = f.__code__.replace(
    co_code=cod, co_names=(name,), co_consts=(const,))

print(eval(f.__code__, {'__builtins__': {}}, {'__builtins__': {}}))
