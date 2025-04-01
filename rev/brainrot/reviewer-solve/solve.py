translation = {
    'bop': 'def',
    'mewing': 'for',
    'diddy': 'in',
    'huzz': 'range',
    'yap': 'print',
    'chat is this real': 'if',
    'only in ohio': 'else',
    'skibidi': 'class',
    'its giving': 'return',
    'lock in': 'from',
    'glaze': 'import',
    'Cooked': 'False',
    'Aura': 'True',
    'twin': '!=',
    'rizz': '+'
}

with open('brain.gyat') as brain_gyat_file:
    brain = brain_gyat_file.read()

with open('rot.gyat') as rot_gyat_file:
    rot = rot_gyat_file.read()

for key, value in translation.items():
    brain = brain.replace(key, value)
    rot = rot.replace(key, value)

with open('brain.py', 'w') as brain_py_file:
    brain_py_file.write(brain)

with open('rot.py', 'w') as rot_py_file:
    rot_py_file.write(rot)

neurons = [[71, 101, 45, 37, 41, 69, 80, 28, 23, 48], [35, 32, 44, 24, 27, 88, 34, 58, 24, 9], [73, 29, 37, 94, 27, 58, 104, 65, 17, 44], [26, 3, 77, 116, 9, 96, 111, 118, 52, 62], [100, 15, 119, 53, 86, 34, 38, 68, 104, 110], [51, 1, 54, 62, 56, 120, 4, 10, 60, 120], [113, 92, 95, 98, 97, 110, 93, 33, 128, 93], [70, 23, 123, 86, 75, 23, 104, 73, 52, 6], [14, 11, 99, 16, 124, 52, 67, 73, 47, 66], [128, 11, 49, 111, 64, 108, 14, 66, 128, 116]]

required_thoughts = [
    [59477, 41138, 59835, 73146, 77483, 59302, 102788, 67692, 62102, 85259],
    [40039, 59831, 72802, 77436, 57296, 101868, 69319, 59980, 84518, 73579466],
    [59783, 73251, 76964, 58066, 101937, 68220, 59723, 85312, 73537261, 7793081533],
    [71678, 77955, 59011, 102453, 66381, 60215, 86367, 74176247, 9263142620, 982652150581],
]

from sympy import symbols, Eq, solve, S

syms = symbols('x0:10')

flag = ''
for x in range(4):
    eqs = []
    for i in range(10):
        expr = S.Zero
        for j in range(10):
            expr += neurons[i][j] * syms[j]
        eqs.append(Eq(expr, required_thoughts[x][i]))
    for c in solve(eqs).values():
        flag += chr(c)
    neurons[:-1] = neurons[1:]
    neurons[-1] = required_thoughts[x]

print(flag)
