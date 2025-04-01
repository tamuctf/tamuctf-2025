# Simple Check

Author: `Addison`

I've given you a binary that allows you to read any file on the system. So, go ahead and read the flag. If you need to debug anything, I've put a helpful call logger on the remote.

## Hints

- It's easier than you think. No binary payload or shellcoding required, I promise.
- Don't waste your time reversing async Rust. Just figure out what the call logger does to log calls.

## Solution

Two commands:
- `/sbin/call-logger --path /sbin/read-any-file --function check &`
- `/sbin/read-any-file /dev/sda`

call-logger is a simple eBPF program which attaches to the specified path and symbol and logs calls to the function starting at that symbol.
read-any-file reads any file -- provided that the `check` variable is set to true.
It is not set to true and there is no way to set it to true from an attacker perspective.

The trick is to recognize that eBPF attachments, specifically uprobes, insert hardware breakpoints (`0xcc` bytes) at the designated symbol.
So, by specifying the `check` variable as the target, we can set the check to true and therefore read any file.

flag:
`gigem{read-any-flag-you-want-just-make-sure-you-check-first}`
