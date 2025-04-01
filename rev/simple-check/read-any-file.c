#include <fcntl.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <unistd.h>

char check __attribute__((section(".text#"))) = 0;

int main(int argc, char **argv) {
  if (argc > 1 && check) {
    int fd = open(argv[1], O_RDONLY);
    sendfile(1, fd, 0, 1024);
    close(fd);
  }
  return 0;
}
