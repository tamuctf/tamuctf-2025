import random
import string

target_string = "gigem{it_does_what_it_does}"
lines = []

lines.append("*T:What's the flag? ")

for i, char in enumerate(target_string):
    lines.append("A")
    r = random.choice(string.ascii_letters)
    while r == char:
        r = random.choice(string.ascii_letters)
    lines.append(f"M:{r}")
    lines.append("YJ:1")
    lines.append(f"M:{char}")
    lines.append("NJ:1")

lines.append("J:2")
lines.append("*T:Wrong!")
lines.append("S")
lines.append("*T:Correct!")
lines.append("S")

with open("flag.wdz", "w") as f:
    f.write("\n".join(lines))

