# Smelter

Author: `flocto`

I've added 2048 bits of security, so there's no way you can forge anything in this smelter.

## Dev Notes

I have no idea if the Makefile is correct, someone should double check.

Also my version of pyasn1 when I was devving might be slightly outdated but I don't think it affects the exploit.

## Solution

See `exp.py`.

The verification does not properly check the padding to fill up the entire chunk, so we can simply pad our wanted message on the right instead, take the cube root, and use that as a valid signature.

Check out [this similar challenge](https://www.hackthebox.com/blog/business-ctf-2022-write-up-bbgun06) for more details about the forgery. 

flag:
`gigem{h0p3fully_y0u_r3aliz3_that_e=3_is_bad_n0w}`
