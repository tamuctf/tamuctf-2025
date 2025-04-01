from z3 import *
import base64


def _encode_block(block):
    out = []
    for x in block:
        x = ZeroExt(2, x)
        o = If(
            x < 26,
            x + BitVecVal(b'A'[0], 8),
            If(
                x < 52,
                x - 26 + BitVecVal(b'a'[0], 8),
                If(
                    x < 62,
                    x - 52 + BitVecVal(b'0'[0], 8),
                    If(
                        x == 62,
                        BitVecVal(b'+'[0], 8),
                        BitVecVal(b'/'[0], 8)
                    )
                )
            )
        )
        out.append(o)

    return out


def symbolic_base64_encode(msg, simp=True):
    blocks = [msg[i:i+3] for i in range(0, len(msg), 3)]

    out = []
    for block in blocks[:-1]:  # all but last block
        a, b, c = [BitVecVal(byt, 8) if isinstance(
            byt, int) else byt for byt in block]

        x1 = Extract(7, 2, a)
        x2 = Concat(Extract(1, 0, a), Extract(7, 4, b))
        x3 = Concat(Extract(3, 0, b), Extract(7, 6, c))
        x4 = Extract(5, 0, c)

        out.extend(_encode_block([x1, x2, x3, x4]))

    last_block = blocks[-1]

    if len(last_block) == 1:
        byt = last_block[0]
        a = BitVecVal(byt, 8) if isinstance(byt, int) else byt

        x1 = Extract(7, 2, a)
        x2 = Concat(Extract(1, 0, a), BitVecVal(0, 4))

        out.extend(_encode_block([x1, x2]))
        out.append(BitVecVal(b'='[0], 8))  # padding
        out.append(BitVecVal(b'='[0], 8))  # padding

    elif len(last_block) == 2:
        a, b = [BitVecVal(byt, 8) if isinstance(byt, int)
                else byt for byt in last_block]

        x1 = Extract(7, 2, a)
        x2 = Concat(Extract(1, 0, a), Extract(7, 4, b))
        x3 = Concat(Extract(3, 0, b), BitVecVal(0, 2))

        out.extend(_encode_block([x1, x2, x3]))
        out.append(BitVecVal(b'='[0], 8))  # padding

    else:
        a, b, c = [BitVecVal(byt, 8) if isinstance(
            byt, int) else byt for byt in last_block]

        x1 = Extract(7, 2, a)
        x2 = Concat(Extract(1, 0, a), Extract(7, 4, b))
        x3 = Concat(Extract(3, 0, b), Extract(7, 6, c))
        x4 = Extract(5, 0, c)

        out.extend(_encode_block([x1, x2, x3, x4]))

    if simp:
        out = [simplify(o) for o in out]

    return out


if __name__ == '__main__':
    msg = b'Hello this is a random message!'
    b64 = base64.b64encode(msg)
    b64_sym = symbolic_base64_encode(msg)

    msg_vec = [BitVec(f'msg_{i}', 8) for i in range(len(msg))]
    b64_sym_vec = symbolic_base64_encode(msg_vec)

    s = Solver()
    for i, c in enumerate(b64):
        s.add(b64_sym_vec[i] == b64[i])

    if s.check() == sat:
        m = s.model()
        dec_msg = bytes([m[x].as_long() for x in msg_vec])
        assert dec_msg == msg, 'Decoded message does not match original message'
    else:
        print('not set')
