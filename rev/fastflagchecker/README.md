# FastFlagChecker

Author: `flocto`

My flagchecker is so fast, I give every bit its own thread!

Flag format is `gigem{[A-Za-z0-9_]+}`.

## Hints

- You can assume each event is only set and waited for once. You can assume also that semaphores will be released exactly as many times as they are waited for.

## Dev Notes

This is a Windows executable so I will not be building it in Make. The binary will be provided as-is (should work).

Someone should also test if this works on Linux with Wine.

Look at `dev_solve/` for a sample solve I created. It relies on the hint assumptions but that should be fine.

## Solution

See `dev_solve` directory.

flag:
`gigem{Try_2_F1nd_0th3r_s0luti0ns_pl3as3}`
