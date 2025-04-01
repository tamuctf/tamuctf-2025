import sys

def restore_magic_bytes(input_filename, output_filename="modified.nii"):
    magic_bytes = bytes.fromhex("6E2B3100")
    
    with open(input_filename, "rb") as f:
        data = bytearray(f.read())
    
    header_size = 348
    magic_position = header_size - 4
    
    if len(data) < header_size:
        print("Error: File is too small to be a valid NIfTI file.")
        return
    
    data[magic_position:magic_position+4] = magic_bytes
    
    with open(output_filename, "wb") as f:
        f.write(data)
    
    print(f"Magic bytes restored and saved to {output_filename}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 script.py <file.nii>")
        sys.exit(1)
    
    restore_magic_bytes(sys.argv[1])
