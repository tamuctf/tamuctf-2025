# OTP

Author: `nhwn`

I heard one-time pads are unbreakable, so it should be impossible to recover the flag, right?

## Solution

This is a simple xor challenge (source is intentionally provided) with 1000 keys, but the twist is that the keys are embedded in a coredump. To recover them, we need to use gdb in an automated fashion. The binary has symbols, so we can grab the keys from each `otp` frame by using `frame <n>; p key`. Once we have the keys, we just need to xor them with the provided ciphertext in `encrypted_flag.bin` to recover the flag.

See `solve.py` for a gdb script that implements this.

flag:
`gigem{if_you_did_that_manually_i_am_so_sorry_for_your_loss}`
