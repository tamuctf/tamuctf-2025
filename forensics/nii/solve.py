import numpy as np
import matplotlib.pyplot as plt

file = open("flag.nii", "rb")
data = bytearray(file.read())
file.close()

header = data[:348]
dimensions = np.frombuffer(header[40:40+16], dtype=np.int16)
datatype = np.frombuffer(header[70:70+2], dtype=np.int16)
pixdim = np.frombuffer(header[76:76+32], dtype=np.float32)

print(f"Dimensions: {dimensions}")
print(f"Datatype: {datatype}")
print(f"Pixdim: {pixdim}")

img_data_start = round(np.frombuffer(header[108:108+4], dtype=np.float32)[0])
print(f"Image data starts at: {img_data_start}")
img_data = data[img_data_start:]

qform_code = np.frombuffer(header[252:252+2], dtype=np.int16)
sform_code = np.frombuffer(header[254:254+2], dtype=np.int16)

srow_x = np.frombuffer(header[280:280+16], dtype=np.float32)
srow_y = np.frombuffer(header[296:296+16], dtype=np.float32)
srow_z = np.frombuffer(header[312:312+16], dtype=np.float32)

row4 = [0, 0, 0, 1]
affine = np.array([srow_x, srow_y, srow_z, row4])

print(f"Qform code: {qform_code}")
print(f"Sform code: {sform_code}")
print(f"Affine: {affine}")

# img_data size is shape * 8 so assume 64bit integers
shape = dimensions[1:dimensions[0]+1]
print(f"Shape: {shape}")
img_data = np.frombuffer(img_data, dtype=np.uint64)
img_data = img_data.reshape(shape, order="F")

slice_index = 0
image_slice = img_data[:, :, slice_index]
plt.imshow(image_slice.T, cmap="gray", origin="lower")
plt.title(f"Slice {slice_index}")
plt.show()

# on slice 0, add text
# slice_index = 0
# image_slice = img_data[:, :, slice_index]
# from PIL import Image, ImageDraw, ImageFont

# min_val = np.min(image_slice)
# max_val = np.max(image_slice)
# print(f"Min: {min_val}, Max: {max_val}")
# print(f"Range: {max_val - min_val}")

# scaled_image_slice_t = (image_slice.T - min_val) / (max_val - min_val) * 255
# scaled_image_slice_t = scaled_image_slice_t.astype(np.uint8)
# # origin is bottom left
# scaled_image_slice_t = np.flipud(scaled_image_slice_t)
# img = Image.fromarray(scaled_image_slice_t)

# text = 'gigem{nii_corrupted_4327}'
# draw = ImageDraw.Draw(img)
# font = ImageFont.load_default(size=12)
# draw.text((10, 10), text, 0, font=font)

# # convert back to nii format
# scaled_image_slice_t = np.array(img)
# scaled_image_slice_t = np.flipud(scaled_image_slice_t)
# image_slice = scaled_image_slice_t.T / 255 * (max_val - min_val) + min_val
# image_slice = image_slice.astype(np.uint64)
# img_data[:, :, slice_index] = image_slice

# # img = Image.fromarray(image_slice.T)
# # img.show()

# # save the new nii file
# new_img_data = img_data.tobytes(order="F")
# new_data = data[:img_data_start] + new_img_data
# file = open("flag.nii", "wb")
# file.write(new_data)
