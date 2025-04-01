import sys
import nibabel as nib
import matplotlib.pyplot as plt

def load_image(file_path):
    ii_img = nib.load(file_path)
    img_data = ii_img.get_fdata()

    slice_index = img_data.shape[2] // 2  
    image_slice = img_data[:, :, slice_index]

    fig, ax = plt.subplots(figsize=(6, 6))
    ax.imshow(image_slice.T, cmap="gray", origin="lower")
    ax.set_title(f"Slice {slice_index}")

    plt.show()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 open.py <file.nii>")
        sys.exit(1)
    
    load_image(sys.argv[1])
