FROM alpine@sha256:beefdbd8a1da6d2915566fde36db9db0b524eb737fc57cd1367effd16dc0d06d

ARG name

RUN apk update && apk add gdb libc-dev gcc make
ADD $name.c /$name.c
ADD Makefile /Makefile
ADD flag.txt /flag.txt
RUN make
