from pwn import *

context.log_level = "debug"
io = remote("tamuctf.com", 443, ssl=True, sni="tamuctf_pycjailplusplus")
io.interactive(prompt="")
