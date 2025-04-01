# Forward to the Past

My school requires student event travel to be filed in advance, but I completely forgot! Worse, Southwest CCDC has already passed! Can you insert a travel record for March 21, 2025?

```
openssl s_client -connect tamuctf.com:443 -servername tamuctf_forward-to-the-past -quiet
```

## Dev Notes

Only provide `forward-to-the-past.c` to competitors, not `db.c`.

## Solution

The challenge asks us to register a travel record for March 21, 2025, but the server only accepts future dates. However, when the date is converted into a timestamp with `mkime`, it is stored in an `int32_t`. This forces an integer overflow similar to the [Year 2038 problem](https://en.wikipedia.org/wiki/Year_2038_problem).

To find the exact date which will wrap around to March 21, 2025, take a timestamp value of March 21, 2025 (1742533200), and add the full value of an unsigned 32-bit integer (4294967295). Their sum of 6037500495 can then be converted back to a date of April 27, 2161 which can be accepted by the server.

flag:
`gigem{7urn_y0ur_c0mpu73r_0ff_83f0r3_m1dn19h7}`
