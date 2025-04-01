FROM alpine:latest AS app

RUN apk add --no-cache qemu-system-x86_64 socat

COPY bzImage /opt/bzImage
COPY disk.img /opt/disk.img
COPY initramfs.img.lz4 /opt/initramfs.img.lz4
COPY entrypoint.sh /opt/entrypoint.sh

COPY crontab /opt/crontab
COPY flag.txt /opt/flag.txt

FROM pwn.red/jail

COPY --from=app / /srv

RUN rm -r /srv/var/tmp && ln -s /tmp /srv/var/tmp && mkdir /srv/app && ln -s /opt/entrypoint.sh /srv/app/run

ARG shell_port
ENV JAIL_PORT=${shell_port} JAIL_POW=45000 JAIL_TMP_SIZE=17179869184 JAIL_DEV=null,zero,urandom,kvm JAIL_PIDS=0 JAIL_TIME=300 JAIL_MEM=0 JAIL_CPU=0
