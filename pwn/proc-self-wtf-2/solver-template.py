from pwn import *

context.log_level = "debug"
io = remote("tamuctf.com", 443, ssl=True, sni="tamuctf_proc-self-wtf-2")
io.interactive(prompt="")
