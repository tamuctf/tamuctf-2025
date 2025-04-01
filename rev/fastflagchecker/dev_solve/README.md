# Solution

My solution involves treating the Events and Semaphores like edges in a graph. 

There was a hint that was never released about assuming each event was only set and waited for once, and each semaphore would be released exactly as many times as they are waited for.

This means we have these rules:
1. Events must only be set by one bit.
2. Events must only be waited for by one bit.
3. Semaphores may be released by multiple bits.
4. Semaphores can only be waited for by one bit (this is already guaranteed by the binary)
5. Semaphores will be waited exactly as many times as they are released.

I parsed the functions using Binary Ninja to extract the useful information, such as the events set and semaphores released when the bit is a 0 or 1. See `funcs.json`.

Then, for each bit, I set their outgoing events with an `Implies` statement, then mark that event as 1 using an `If`.
```python
    for event in zero_half["to_events"]:
        events[event] += If(bit == 0, 1, 0)
        s.add(Implies(bit == 0, event_setter[event] == i))
    
    for event in one_half["to_events"]:
        events[event] += If(bit == 1, 1, 0)
        s.add(Implies(bit == 1, event_setter[event] == i))
```

For the semaphores, I do something similar, but also include their proper count.
```python
    for sema, cnt in zero_half["to_semaphores"]:
        semaphores[sema] += If(bit == 0, cnt, 0)
    
    for sema, cnt in one_half["to_semaphores"]:
        semaphores[sema] += If(bit == 1, cnt, 0)
```

Finally, I add all the constraints to the solver, enforcing the bit to be either 0 or 1 and adding the proper conditions.
```python
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
```

This generates 32 solutions, which is small enough to test manually. Only the correct flag `gigem{Try_2_F1nd_0th3r_s0luti0ns_pl3as3}` correctly validates in the binary (which is good).
