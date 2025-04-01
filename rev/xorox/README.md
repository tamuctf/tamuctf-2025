# Xorox

Author: `flocto`

Today I will xor my flag with a key. 

![:clueless:](https://cdn.frankerfacez.com/emoticon/670425/4)

## Dev Notes

Requires AVX2 to run.
Please test with multiple decompilers / different decompliation options to see how annoying it is.

## Solution

We know from quick inspection that lanes remain isolated and that the string should be fully zeroed out at the end, so we can brute this a character at a time without thinking about garbage SIMD nonsense:

```bash
string="gigem"; for j in $(seq 0 31); do string="${string}$(for i in $(seq 1 127); do if ! [[ $i -eq 39 ]] && [[ $(gdb ./xorox -nx --batch -ex 'break *0x4011aa' -ex "run '${string}$(printf "\x$(printf "%x" $i)")'" -ex 'print $ymm2.v32_int8['"$j"']' | tail -n 1 | cut -d' ' -f3) -eq 0 ]]; then printf "\x$(printf "%x" $i)"; fi & done | head -c 1; kill $(jobs -p) 2>/dev/null)"; echo "${string}"; done
```

### Alternate Solution
Just xor the correct things together to get the flag:
```python
a = b'\xfbo\xf3\xcd:\x7f\x8c*\xaa\xca`&\xf3\xee\xc2\x8c\x92\xb5\xa3\xd7a\xfd\xa1\xef^\x02\x90*\xd2\xc2\xdd\xa9'
b = b'\xa8\x00\x81\xbfCS\xac^\xd8\xb3@J\x9c\x81\xa9\xe5\xfc\xd2\x83\xb2\r\x8e\xc4\x986g\xe2O\xf2\xf8\xf4\x89'
c = b'\x80\x19\xc0\xbfC \xca\x1e\x9f\xbe?u\xba\xa3\x86\xd3\xea\x85\xd1\x88\x16\xcc\xd5\x87\x010\xcfA\xb7\xbb\xae\xd4'

print(bytes(a[i] ^ c[i] for i in range(len(a))))
```

flag:
`gigem{v3ry_F45t_SIMD_x0r_w1th_2_keys}`
