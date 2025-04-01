import json 
from z3 import *

N = 40
BITS = N * 8
flag = [BitVec(f"flag_{i}", 8) for i in range(N)]
# bits[i * 8 + j] = (flag[i] >> j) & 1
bits = [Extract(i % 8, i % 8, flag[i // 8]) for i in range(BITS)]
s = Solver()

known = b'gigem{'
# known = b'gigem{Try_2_F1nd_0th3r_' # look at the 32 solutions and then inspection
for i in range(len(known)):
    s.add(flag[i] == known[i])
s.add(flag[-1] == ord('}'))

# [A-Za-z0-9_{}]
for i in range(40):
    s.add(Or(
        And(flag[i] >= ord('A'), flag[i] <= ord('Z')),
        And(flag[i] >= ord('a'), flag[i] <= ord('z')),
        And(flag[i] >= ord('0'), flag[i] <= ord('9')),
        flag[i] == ord('_'),
        flag[i] == ord('{'),
        flag[i] == ord('}'),
    ))
    # s.add(And(flag[i] >= 0x20, flag[i] <= 0x7e))

event_count = 0x409
events = [Int(f"event_{i}") for i in range(event_count)]
event_setter = [Int(f"event_setter_{i}") for i in range(event_count)]
event_waiter = [Int(f"event_waiter_{i}") for i in range(event_count)]

sema_count = 0x12e
semaphores = [Int(f"semaphore_{i}") for i in range(sema_count)]
semaphore_owner = [Int(f"semaphore_owner_{i}") for i in range(sema_count)]

funcs = json.loads(open("funcs.json").read())
for i, (zero_half, one_half) in enumerate(funcs):
    bit = bits[i]
    # parse outgoing first
    for event in zero_half["to_events"]:
        events[event] += If(bit == 0, 1, 0)
        # event_setter[event] = If(bit == 0, i, event_setter[event])
        s.add(Implies(bit == 0, event_setter[event] == i))
    
    for event in one_half["to_events"]:
        events[event] += If(bit == 1, 1, 0)
        # event_setter[event] = If(bit == 1, i, event_setter[event])
        s.add(Implies(bit == 1, event_setter[event] == i))
    
    for sema, cnt in zero_half["to_semaphores"]:
        semaphores[sema] += If(bit == 0, cnt, 0)
    
    for sema, cnt in one_half["to_semaphores"]:
        semaphores[sema] += If(bit == 1, cnt, 0)

for i, (zero_half, one_half) in enumerate(funcs):
    bit = bits[i]

    zero_half_conds = [bit == 0]
    sc, si = zero_half["func_semaphore"]
    if si is not None:
        zero_half_conds.append(semaphores[si] == sc)
        zero_half_conds.append(semaphore_owner[si] == i)
    
    for event in zero_half["from_events"]:
        zero_half_conds.append(event_waiter[event] == i)

    zero_half_conds = And(zero_half_conds)

    one_half_conds = [bit == 1]
    sc, si = one_half["func_semaphore"]
    if si is not None:
        one_half_conds.append(semaphores[si] == sc)
        one_half_conds.append(semaphore_owner[si] == i)
    
    for event in one_half["from_events"]:
        one_half_conds.append(event_waiter[event] == i)

    one_half_conds = And(one_half_conds)

    s.add(Implies(bit == 0, And(zero_half_conds, Not(one_half_conds))))
    s.add(Implies(bit == 1, And(one_half_conds, Not(zero_half_conds))))

# all events are used once
s.add(And([event == 1 for event in events]))

total_sols = 0
while s.check() == sat:
    m = s.model()
    out = bytes([m[flag[i]].as_long() for i in range(40)])
    print(out)
    s.add(Or([flag[i] != m[flag[i]] for i in range(40)]))
    total_sols += 1

else:
    print("unsat")

# i couldnt figure out a way to get it under 32 solutions, if someone else has any other ideas please let me know
print(total_sols, "solutions") 