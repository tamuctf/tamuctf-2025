from binaryninja.binaryview import BinaryView
from binaryninja.highlevelil import TokenList

# for typing
bv: BinaryView = eval("bv")

def parse_half(half: list[TokenList]):
    sema_count = 0
    sema_index = None
    from_events = []
    to_events = []
    to_semaphores = []

    for line in half:
        line_str = "".join(token.text for token in line.tokens)
        if line_str.startswith("return "):
            line_str = line_str.split(" ", 1)[1]

        if line_str.startswith("WaitForSingleObject"):
            handle = line_str.split("(")[1].split(",")[0]
            if handle.startswith("events"):
                from_events.append(int(handle.split("[")[1].split("]")[0], 16))
            else:
                sema_index = int(handle.split("[")[1].split("]")[0], 16)
        elif "while" in line_str:
            sema_count = int(line_str.split("<")[1].split(")")[0], 16)
        elif line_str.startswith("SetEvent"):
            event_idx = int(line_str.split("[")[1].split("]")[0], 16)
            to_events.append(event_idx)
        elif line_str.startswith("ReleaseSemaphore"):
            sema_idx = int(line_str.split("[")[1].split("]")[0], 16)
            sema_cnt = int(line_str.split(",")[1], 16)
            to_semaphores.append((sema_idx, sema_cnt))

    # return (sema_count, sema_index), to_semaphores, to_events, from_events
    print((sema_count, sema_index), to_semaphores, from_events, to_events)
    return {
        "func_semaphore": (sema_count, sema_index),
        "to_semaphores": to_semaphores,
        "from_events": from_events,
        "to_events": to_events
    }

funcs = []
funcs_arr = bv.get_symbols_by_raw_name("funcs")[0]
for i in range(0x140):
    func_addr = bv.read_pointer(funcs_arr.address + i * 8)

    # print(f"0x{func:x}")
    func = bv.get_function_at(func_addr)
    if func is None:
        continue
    
    one_half = []
    zero_half = []
    on_second = False
    for line in func.hlil.instructions:
        if "".join(map(str, line.tokens)) == "int32_t var_18 = 0":
            continue
        
        if on_second:
            zero_half.append(line)
        else:
            one_half.append(line)

        if "return " == line.tokens[0].text:
            on_second = True

    first, *one_half = one_half
    if first.tokens[3].text.strip() == "==":
        one_half, zero_half = zero_half, one_half

    # print(zero_half)
    # print(one_half)

    zero_half = parse_half(zero_half)
    one_half = parse_half(one_half)
    funcs.append((zero_half, one_half))

print(len(funcs))

import json
json.dump(funcs, open("funcs.json", "w"), indent=4)