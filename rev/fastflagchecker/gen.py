import random
from collections import defaultdict

# flag = b"gigem{para11el_Do3snt_alw4ys_M34N_Fast!}"
# flag = b"gigem{PLS_ch3cK_4_0th3r_s01uTi0N5_L0lXd}"
flag = b"gigem{Try_2_F1nd_0th3r_s0luti0ns_pl3as3}"

nodes = []
bits = {}
for i in range(len(flag)):
    for j in range(8):
        b = (flag[i] >> j) & 1
        nodes.append((i * 8 + j, b))
        bits[i * 8 + j] = b

print(len(nodes))
FIRST_LAST_RANGE = (6, 18)
REST_RANGE = (15, 35)

random.shuffle(nodes)
first = nodes[:random.randint(*FIRST_LAST_RANGE)]
nodes = nodes[len(first):]
last = nodes[-random.randint(*FIRST_LAST_RANGE):]
nodes = nodes[:-len(last)]

rest = []
while nodes:
    r = random.randint(*REST_RANGE)
    rest.append(nodes[:r])
    nodes = nodes[r:]
rest.append(last)

while True:
    split_nodes = rest.copy()
    edges = defaultdict(list)
    cur_nodes = first
    EDGE_PERCENT = 0.3
    # print("generating edges")
    ec = 0
    for i in range(len(split_nodes)):
        for r in split_nodes[0]:
            for c in cur_nodes:
                if random.random() < EDGE_PERCENT:
                    edges[c[0]].append(r[0])
                    ec += 1

        cur_nodes = split_nodes[0]
        split_nodes = split_nodes[1:]

    # print(f"generated {ec} edges")
    # print(len(edges), len(flag) * 8, len(last))
    if len(edges) != len(flag) * 8 - len(last): # make sure every node except the last ones have an edge
        # print("retry")
        continue

    break

inv_edges = defaultdict(list)
for k, vv in edges.items():
    for v in vv:
        inv_edges[v].append(k)
# print(edges)

edge_types = {}
SEMAPHORE_BIAS = 0.55
SEMAPHORE_RANGE = (1, 4)
semaphore_counts = {}
events = []
for k, vv in edges.items():
    for v in vv:
        if random.random() < SEMAPHORE_BIAS:
            sc = random.randint(*SEMAPHORE_RANGE)
            if v not in semaphore_counts:
                semaphore_counts[v] = 0
            semaphore_counts[v] += sc
            edge_types[(k, v)] = ('semaphore', sc)
        else:
            edge_types[(k, v)] = 'event'
            events.append(f"Event_{k}_{v}")

semaphores = list(semaphore_counts.keys())

print(f"events: {len([v for v in edge_types.values() if v == 'event'])}")
print(f"semaphores: {len([v for v in edge_types.values() if v[0] == 'semaphore'])}")

print(semaphore_counts)

all_code = [
    '#include <Windows.h>',
    '#include <cstdio>',
    '#include <cstring>',
    '#include <cstdlib>',
]

# CREATE EVENTS
all_code.append(f"HANDLE events[{len(events)}];")
all_code.append("void CreateEvents() {")
all_code.append(f"for (int i = 0; i < {len(events)}; i++) {{")
all_code.append("events[i] = CreateEvent(NULL, FALSE, FALSE, NULL);")
all_code.append("}")
all_code.append("}")
event_mapping = list(range(len(events)))
random.shuffle(event_mapping)
event_mapping = {events[i]: event_mapping[i] for i in range(len(events))}

# CREATE SEMAPHORES
all_code.append(f"HANDLE semaphores[{len(semaphores)}];")
all_code.append("void CreateSemaphores() {")
all_code.append(f"for (int i = 0; i < {len(semaphores)}; i++) {{")
all_code.append("semaphores[i] = CreateSemaphore(NULL, 0, 1337, NULL);")
all_code.append("}")
all_code.append("}")
semaphore_mapping = list(range(len(semaphores)))
random.shuffle(semaphore_mapping)
semaphore_mapping = {semaphores[i]: semaphore_mapping[i] for i in range(len(semaphores))}

# CREATE THREADS
BAD_EVENT_RANGE = (0, 5)
BAD_SEMAPHORE_BIAS = 0.8 # give about a 20% chance of no semaphores
BAD_SEMAPHORE_RANGE = (1, 20)
for i in range(len(flag) * 8):
    all_code.extend([
        f"void WINAPI Thread_{i}(int bit) {'{'}",
        "int i = 0;"
    ])

    # good code
    good_cod = []
    for from_edge in inv_edges[i]:
        if edge_types[(from_edge, i)] == 'event':
            # good_cod.append(f"WaitForSingleObject(Event_{from_edge}_{i}, INFINITE);")
            good_cod.append(f"WaitForSingleObject(events[{event_mapping[f'Event_{from_edge}_{i}']}], INFINITE);")

    if i in semaphore_counts:
#         good_cod.append(f"""for (i = 0; i < {semaphore_counts[i]}; i++) {{
#     WaitForSingleObject(Semaphore_{i}, INFINITE);
# }}""")
        good_cod.append(f"""for (i = 0; i < {semaphore_counts[i]}; i++) {{
    WaitForSingleObject(semaphores[{semaphore_mapping[i]}], INFINITE);
}}""")

    good_cod.append("// good checks done")

    for to_edge in edges[i]:
        if edge_types[(i, to_edge)] == 'event':
            # good_cod.append(f"SetEvent(Event_{i}_{to_edge});")
            good_cod.append(f"SetEvent(events[{event_mapping[f'Event_{i}_{to_edge}']}]);")
        else:
            _, sc = edge_types[(i, to_edge)]
            # good_cod.append(f"ReleaseSemaphore(Semaphore_{to_edge}, {sc}, NULL);")
            good_cod.append(f"ReleaseSemaphore(semaphores[{semaphore_mapping[to_edge]}], {sc}, NULL);")

    # bad code
    bad_cod = []
    # bad_cod.extend([f"WaitForSingleObject({event}, INFINITE);" for event in random.sample(events, random.randint(*BAD_EVENT_RANGE))])
    bad_cod.extend([f"WaitForSingleObject(events[{event_mapping[event]}], INFINITE);" for event in random.sample(events, random.randint(*BAD_EVENT_RANGE))])

    if random.random() < BAD_SEMAPHORE_BIAS and i in semaphore_counts:
#         bad_cod.append(f"""for (i = 0; i < {random.randint(*BAD_SEMAPHORE_RANGE)}; i++) {{
#     WaitForSingleObject(Semaphore_{i}, INFINITE);
# }}""")
        # idx = random.choice(list(semaphore_mapping.keys()))
        bad_cod.append(f"""for (i = 0; i < {random.randint(*BAD_SEMAPHORE_RANGE)}; i++) {{
    WaitForSingleObject(semaphores[{semaphore_mapping[i]}], INFINITE);
}}""")

    bad_cod.append("// bad checks done")

    fake_events_semas = []
    for fake_event in random.sample(events, random.randint(*BAD_EVENT_RANGE)):
        # fake_events_semas.append(f"SetEvent({fake_event});")
        fake_events_semas.append(f"SetEvent(events[{event_mapping[fake_event]}]);")
    
    for fake_sema in random.sample(semaphores, random.randint(*BAD_EVENT_RANGE)):
        # fake_events_semas.append(f"ReleaseSemaphore(Semaphore_{fake_sema}, {random.randint(1, 3)}, NULL);")
        fake_events_semas.append(f"ReleaseSemaphore(semaphores[{semaphore_mapping[fake_sema]}], {random.randint(*SEMAPHORE_RANGE)}, NULL);")

    random.shuffle(fake_events_semas)
    bad_cod.extend(fake_events_semas)

    if bits[i] == 0:
        good_cod, bad_cod = bad_cod, good_cod

    all_code.append("if (bit) {")
    all_code.extend(good_cod)
    all_code.append("} else {")
    all_code.extend(bad_cod)
    all_code.append("}")
    
    all_code.append("}")

# THREADS
all_code.append("HANDLE threads[] = {")
threads = []
for i in range(len(flag) * 8):
    threads.append(f"Thread_{i}")
all_code.append(", ".join(threads))
all_code.append("};")

# MAIN
all_code.append("int main() {")
all_code.append("CreateEvents();")
all_code.append("CreateSemaphores();")
all_code.append("""
char input[100];
printf("> ");
fgets(input, 100, stdin);
input[strcspn(input, "\\n")] = 0;
                
if (strlen(input) != 40) {
    printf("Wrong");
    return 1;
}
                
HANDLE threadHandles[320];
for (int i = 0; i < 320; i++) {
    int bit = (input[i / 8] >> (i % 8)) & 1;
    threadHandles[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threads[i], (LPVOID)bit, 0, NULL);
}
""")

all_code.append(f"""
    HANDLE finalHandles[{len(last)}] = {{ {", ".join([f"threadHandles[{x[0]}]" for x in last])} }};
    int res = WaitForMultipleObjects({len(last)}, finalHandles, TRUE, 5000); // 5 seconds
""")

all_code.append("""
if (res == WAIT_TIMEOUT) {
    printf("Wrong");
    return 1;
}
                
printf("Correct");
return 0;
}""")

open("src.cpp", "w").write("\n".join(all_code))
