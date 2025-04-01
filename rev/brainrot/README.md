# Brainrot

Author: `flocto`

This challenge is only solvable in Ohio 😂😂.

Note: This challenge requires `-k` to run properly.

## Solution

Looking at `rot.gyat` and `brain.gyat`, we can see that they are just Python scripts with built-in functions, keywords, and operations replaced by brainrot terms. To obtain the original source code, we can infer what each of these terms refers to and write a script to replace them.

Once the original source code is obtained, we can run `rot.py`. We can print out the value of `neurons` after `brain.rot()` is called and use it to reverse the loop calling `brain.think()`. 

`brain.think()` multiplies each chunk of 10 characters of the flag against the 10 values in each of the 10 sublists in `neurons`, saving the sum of each sublist multiplication in `thoughts`. Since we know `required_thoughts`, we can simply create a 10 variable system of equations for each 10 character chunk of the flag. Solving all 4 of these equations gives us the flag.

flag:
`gigem{whats_up_my_fellow_skibidi_sigmas}`
