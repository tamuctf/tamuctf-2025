from PIL import Image
import numpy as np
from base64 import b64decode

im = Image.open("image.png")

arr = np.array(im)
print(arr.shape)

arr = arr[10::12,10::12,0]
arr = arr.flatten()
arr = list(arr)

arr = ["0" if x == 0 else "1" for x in arr]
text = "".join(arr)
print(text)
binary = [text[i:i+8] for i in range(0,len(text),8)]
chars = [chr(int(b,2)) for b in binary]
text = "".join(chars)
print(text)
print(b64decode(text))