# Stack

Author: `nhwn`

It's nice to review our fundamental data structures every now and then.

## Solution

Since the shellcode buffer is RWX, the main idea is to do a `read()` syscall for an unrestricted second stage. Since the capstone filter only allows for pushes and pops with registers, getting immediates for injecting a `syscall` instruction is difficult. The intended solution is to use the number of bytes read (stored on the stack) to generate the `syscall` immediate 0x050f (we can pad out our payload up to 0x1000 bytes). To get the `syscall` immediate into a register, we can use repeated `pop` instructions to overlap `rsp` with the stack variable. We can use a similar technique to scoop a zero off the stack. To actually inject the `syscall` instruction, we can make `rsp` point downrange in the RWX buffer by moving `rdx` (the shellcode is executed via `call rdx`) into `rsp`, spamming `pop` to get downrange, then injecting `syscall` with a final `push`. For the second stage, I used stock pwntools shellcode to print the flag out.

flag:
`gigem{popping_off_sheesh_i_hope_ur_winnin_son}`
