#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -s -masm=intel -mavx2 -o nada main.c

typedef unsigned char u8;

u8 real_key[32] = "\x80\x19\xc0\xbf\x43\x20\xca\x1e\x9f\xbe\x3f\x75\xba\xa3\x86\xd3\xea\x85\xd1\x88\x16\xcc\xd5\x87\x01\x30\xcf\x41\xb7\xbb\xae\xd4";

int check(u8 *flag, u8 *fake_key) {
    u8 enc[32] = "\xfb\x6f\xf3\xcd\x3a\x7f\x8c\x2a\xaa\xca\x60\x26\xf3\xee\xc2\x8c\x92\xb5\xa3\xd7\x61\xfd\xa1\xef\x5e\x02\x90\x2a\xd2\xc2\xdd\xa9";
    
    int result = 0;
    // hope you enjoy simd
    asm volatile(
        "xor rax, rax\n"
        "mov rcx, %0\n"
        "mov rdx, %1\n"
        "mov rbx, %2\n"
        "vmovdqu ymm0, [rdx]\n"
        "vmovdqu ymm1, [rcx]\n"
        "vmovdqu ymm2, [rbx]\n"
        "vpxor ymm0, ymm0, ymm1\n"
        "vpxor ymm1, ymm1, ymm2\n"
        "vpxor ymm1, ymm1, ymm7\n"
        "vpaddd ymm2, ymm0, ymm1\n"
        "vpsubd ymm2, ymm2, ymm0\n"
        // check if ymm2 is all zeros
        "vptest ymm2, ymm2\n"
        "setz al\n"
        "mov %3, eax\n"
        :
        : "r"(flag), "r"(fake_key), "r"(enc), "m"(result)
        : "rax", "rdx", "rbx", "r10"
    );

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <flag>\n", argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "gigem", 5) != 0) {
        goto fail;
    }

    // move real_key into ymm7
    asm volatile(
        "vmovdqu ymm7, [%0]\n"
        :
        : "r"(real_key)
    );

        
    u8 fake_key[32] = "\xa8\x00\x81\xbf\x43\x53\xac\x5e\xd8\xb3\x40\x4a\x9c\x81\xa9\xe5\xfc\xd2\x83\xb2\x0d\x8e\xc4\x98\x36\x67\xe2\x4f\xf2\xf8\xf4\x89";

    if (!check(&argv[1][5], fake_key)) {
        fail:
        puts("Nope");
        return 1;
    }

    puts("Yup");
    return 0;
}