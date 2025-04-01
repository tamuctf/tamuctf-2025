# What It Does

Author: `flocto`

What does it do? Does it do what it does?

## Solution

A quick visual inspection shows the characters of `gigem` appearing on every other `M:` line, so we just grep this out.

```bash
cat flag.wdz  | grep "^M:" | cut -d':' -f2 | awk '(NR + 1) % 2 {print} !((NR + 1) % 2) && /pattern/ {print}' | paste -sd ''
```

flag:
`gigem{it_does_what_it_does}`
