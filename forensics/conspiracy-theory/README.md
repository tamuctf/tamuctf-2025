# Conspiracy Theory

Author: `moveslow`

You've gotta believe me bro there's something here man. It's not a conspiracy. It's real im telling you!

## Hints

## Dev Notes

## Solution


Use any tool you want to first find the mp3. Pdf parser to locate where it is, binwalk to extract it both work.
Two links for understanding how a mp3 works http://www.mp3-tech.org/programmer/frame_header.html and https://www.codeproject.com/Articles/8295/MPEG-Audio-Frame-Header

Then Realize that the mp3 doesn't play because the audio frame headers have been removed.
The mp3 header is still there though it's fff3 64c4 which is 1111 1111 1111 1100 0110 0100 1100 0100 in binary 

The audio frame size can then be calculated from these headers 
in a mp3 the first FFF3 bytes indicate that it's a mp3 header becuase it's the magic bytes for a mp3 header.
We know its specifically MPEG layer 3 version 2 because the bits are 01 and 10 from bits [20-17]

We can then use this to reference the table to find out that the mp3 also uses a bit rate index of 48kbps
We can use the same table to tell it has a sampling rate of 24khz
We also know that the samples per frame is 576 because it's a mpeg 2 layer 3
Note that the audio frame size for a mp3 can be calculated by Bit rate/sampling rate which is ((samples per frame/8)*bit rate)/sampling rate
This gives us ((576/8)*48000)/24000 = 144 bytes between each audio frame. 

Now just add fff3 64c4 every 144 bytes starting from the beginning of the mp3 header. You could calculate the number of times you'd need to repeat this by checking the file size of the mp3
in a pdf parser tool then calculating hte number of frames you'd need to fit the mp3. Or just eyeball it until you can hear the full flag, that works too. 

```
import os


def modify_file(input_file_path, output_file_path, start_address, replacement, interval, repeat_count):
    with open(input_file_path, 'rb') as file:
        content = bytearray(file.read())

    file_size = len(content)

    replacement_bytes = bytes.fromhex(replacement.replace(' ', ''))

    for i in range(repeat_count):
        address = start_address + i * interval
        if address + 4 <= file_size:
            content[address:address+4] = replacement_bytes
        else:
            print(f"Warning: Reached end of file at iteration {i+1}")
            break

    with open(output_file_path, 'wb') as file:
        file.write(content)


input_file_path = 'conspiracy.pdf' 
output_file_path = 'output_file.pdf'  
start_address = 0x00054cb8 
replacement = 'fff3 64c4' 
interval = 144  
repeat_count = 1100 

modify_file(input_file_path, output_file_path, start_address, replacement, interval, repeat_count)
print(f"File modification completed. Output written to: {output_file_path}")
```

flag:
`gigem{mp3_is_so_free_electric_beegalee}`