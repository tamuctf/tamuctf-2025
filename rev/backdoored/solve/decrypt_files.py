import os
import xxtea # pip3 install xxtea

key = b'b4Ckd0Orb4Ckd0Or'

path = os.path.join(os.path.dirname(__file__), '../server/')

worlds = [
    'world',
    'world_nether',
    'world_the_end'
]

region = {
    'world': 'region',
    'world_nether': 'DIM-1/region',
    'world_the_end': 'DIM1/region'
}

def decrypt_file(file):
    with open(file, 'rb') as f:
        data = f.read()
    data = xxtea.decrypt(data, key, padding=False)
    return data

for world in worlds:
    dir_path = os.path.join(path, world)

    for file in os.listdir(dir_path):
        if file.endswith('.enc'):
            file_path = os.path.join(dir_path, file)
            data = decrypt_file(file_path)
            with open(file_path[:-4], 'wb') as f:
                f.write(data)

    region_path = os.path.join(dir_path, region[world])
    for file in os.listdir(region_path):
        if file.endswith('.mca.enc'):
            file_path = os.path.join(region_path, file)
            data = decrypt_file(file_path)
            with open(file_path[:-4], 'wb') as f:
                f.write(data)
    