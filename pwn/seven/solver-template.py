from pwn import *

context.log_level = "debug"
io = remote("tamuctf.com", 443, ssl=True, sni="tamuctf_seven")
io.interactive(prompt="")
