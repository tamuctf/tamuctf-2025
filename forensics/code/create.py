import numpy as np
import matplotlib.pyplot as plt

# flag_text = 'Wow!!!!!!!!! You just got the message and the flag: gigem{b1n4ry_d3c0d1n6_h319y2z8}'
flag_text = 'V293ISEhISEhISEhIFlvdSBqdXN0IGdvdCB0aGUgbWVzc2FnZSBhbmQgdGhlIGZsYWc6IGdpZ2Vte2IxbjRyeV9kM2MwZDFuNl9oMzE5eTJ6OH0='

binary_flag = ''.join(format(ord(c), '08b') for c in flag_text)

grid_size = int(np.ceil(np.sqrt(len(binary_flag))))
grid = np.zeros((grid_size, grid_size))

for i, bit in enumerate(binary_flag):
    row = i // grid_size
    col = i % grid_size
    grid[row, col] = 1 if bit == '1' else 0

print("Binary Array:")
print(grid)

output_image_path = 'image.png'
plt.imshow(grid, cmap='gray', interpolation='nearest')
plt.axis('off')
plt.savefig(output_image_path, bbox_inches='tight', pad_inches=0)

print(f"Image saved as {output_image_path}")
