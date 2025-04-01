# proc-self-wtf-1

Author: `Addison`

I put my flag in a container, but I forgot it. All that container does is sleep! Can you get my flag back?

## Hints

- You don't need any special payload for this one. Pinky promise.

## Solution

cron's running and it's launching that sleep container.
So, how do we access its filesystem?

Just `cat /proc/$(pidof sleep)/cwd/flag.txt` -- eventually, the sleep process in the docker container becomes active from the cron job, and because we share uid/gid, we can access it.
This is a "magic link" that allows us to traverse directories which aren't accessible by their absolute path.

flag:
`gigem{magic-link-were-not-in-kansas-anymore-ee984b993df20bc507d70525553de887}`
