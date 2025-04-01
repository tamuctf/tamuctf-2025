from pathlib import Path
from subprocess import run

def xor(a, b):
    return bytes([x ^ y for x, y in zip(a, b)])

c = Path("encrypted_flag.bin").read_bytes()

try:
    import gdb
    inf = gdb.selected_inferior()
    start = 4
    num_keys = 1000
    for i in range(start, start + num_keys):
        gdb.execute(f"frame {i}")
        # you can use .bytes in later versions of gdb, see:
        # https://sourceware.org/bugzilla/show_bug.cgi?id=13267
        addr = gdb.selected_frame().read_var("key").address
        key = bytes(inf.read_memory(addr, len(c)))
        c = xor(c, key)
    print(c.decode())
except ModuleNotFoundError:
    args = ["gdb", "otp", "dump", "-ex", "source solve.py", "-ex", "q"]
    res = run(args, capture_output=True)
    for line in res.stdout.splitlines():
        if b"gigem" in line:
            print(line.decode())
