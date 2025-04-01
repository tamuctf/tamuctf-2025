# proc-self-wtf-2

Author: `Addison`

I recovered my old flag, and to prevent it from happening again I put it in a local directory. But, I misconfigured the permissions on the files and now I can't read it again. Can you get it back again? Sorry :sweat_smile:

## Hints

- You may need to create a payload for this one. The shell is provided over serial connection; you may need to limit throughput with e.g. `pv -q -L 128`.
- A toolchain is provided. No need to fire binaries over the wire.
- Docker is out of date. Strange...

## Solution

This exploits a [race condition in moby](https://github.com/moby/moby/releases/tag/v26.1.4).
The TL;DR is that the Go runtime implementation of [removeAll is susceptible to symlink races](https://go-review.googlesource.com/c/go/+/588495) and this is exploitable from the magic link exploited in the first part.
Here, we manipulate the container filesystem as it is being removed, where removal is performed by a process in the root, not the container.
As a result, symlink swaps resolve to the host filesystem.
We use `RENAME_EXCHANGE` as a better assurance that we actually perform the TOCTOU and fill the targeted `scratch` file with >1024 files so that [Go reopens the folder without checking symlink data](https://github.com/golang/go/blob/go1.22.2/src/os/removeall_at.go#L97)

The solve script simply submits a small binary which performs atomic exchanges of a folder and a symlink s.t. we can confuse the Go runtime.

flag:
`gigem{go-go-gadget-toctou-delete-cd5feab55198c7d9d570a3a1bae1e2f9}`
