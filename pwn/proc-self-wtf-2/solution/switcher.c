#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

// shims for musl
#define RENAME_EXCHANGE  (1 << 1)

int renameat2(int oldfd, const char *old, int newfd, const char *new, unsigned flags)
{
  return syscall(SYS_renameat2, oldfd, old, newfd, new, flags);
}

int main(int argc, char **argv) {
  if (renameat2(AT_FDCWD, "evil", AT_FDCWD, "link", RENAME_EXCHANGE) != 0) {
    printf("renameat2 failed: %s\n", strerror(errno));
    return -1;
  }
  return 0;
}
