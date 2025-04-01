#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <seccomp.h>

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void no_one_gadget_for_you() {
    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ALLOW);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execve), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execveat), 0);
    seccomp_load(ctx);
}

#define RWX 0x500000

int main() {
    init();
    no_one_gadget_for_you();
    char* code = mmap(RWX, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED_NOREPLACE, -1, 0);
    if (code != MAP_FAILED) {
        read(0, RWX, 7);
        mprotect(RWX, 0x1000, PROT_READ | PROT_EXEC);
        ((void (*)())RWX)();
    }
}
