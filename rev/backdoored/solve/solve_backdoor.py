from base64 import b64decode, b64encode
from z3 import *
from b64 import symbolic_base64_encode

xor = (0x51e02052f115e3b).to_bytes(8, 'little')

msg_vec = [BitVec(f'msg_{i}', 8) for i in range(8)]
b64_sym_vec = symbolic_base64_encode(msg_vec)

s = Solver()

for i in range(8):
    s.add(msg_vec[i] ^ b64_sym_vec[i] == xor[i])

if s.check() == sat:
    while s.check() == sat:
        m = s.model()
        print(''.join([chr(m[msg_vec[i]].as_long()) for i in range(8)]))
        s.add(Or([msg_vec[i] != m[msg_vec[i]] for i in range(8)]))
else:
    print('unsat')


# backdoor2 check
msg_vec = [BitVec(f'msg_{i}', 8) for i in range(12)]
s = Solver()
# 00002caf        if (data_5131 != 0 && *arg1 == arg1[8] && arg1[8] == arg1[9]
# 00002caf                && zx.d(arg1[1]) + zx.d(*arg1) == 0xdf
# 00002caf                && zx.d(arg1[2]) + zx.d(*arg1) == 0xce
# 00002caf                && zx.d(arg1[3]) + zx.d(*arg1) == 0xd1
# 00002caf                && zx.d(arg1[4]) + zx.d(*arg1) == 0xd0
# 00002caf                && zx.d(arg1[5]) + zx.d(*arg1) == 0xd2
# 00002caf                && zx.d(arg1[6]) + zx.d(*arg1) == 0xda
# 00002caf                && zx.d(arg1[7]) + zx.d(*arg1) == 0xd3
# 00002caf                && zx.d(arg1[8]) + zx.d(*arg1) == 0xde
# 00002caf                && zx.d(arg1[9]) + zx.d(*arg1) == 0xde
# 00002caf                && zx.d(arg1[0xa]) + zx.d(*arg1) == 0xe1
# 00002caf                && zx.d(arg1[0xb]) + zx.d(*arg1) == 0x90)
s.add(msg_vec[0] == msg_vec[8])
s.add(msg_vec[8] == msg_vec[9])

s.add(msg_vec[0] + msg_vec[1] == 0xdf)
s.add(msg_vec[0] + msg_vec[2] == 0xce)
s.add(msg_vec[0] + msg_vec[3] == 0xd1)
s.add(msg_vec[0] + msg_vec[4] == 0xd0)
s.add(msg_vec[0] + msg_vec[5] == 0xd2)
s.add(msg_vec[0] + msg_vec[6] == 0xda)
s.add(msg_vec[0] + msg_vec[7] == 0xd3)
s.add(msg_vec[0] + msg_vec[8] == 0xde)
s.add(msg_vec[0] + msg_vec[9] == 0xde)
s.add(msg_vec[0] + msg_vec[10] == 0xe1)
s.add(msg_vec[0] + msg_vec[11] == 0x90)

if s.check() == sat:
    m = s.model()
    print(''.join([chr(m[msg_vec[i]].as_long()) for i in range(12)]))
else:
    print('unsat')