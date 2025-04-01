FROM debian@sha256:18023f131f52fc3ea21973cabffe0b216c60b417fd2478e94d9d59981ebba6af AS app

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y qemu-system qemu-utils wget cloud-image-utils libguestfs-tools gcc socat netcat-traditional

WORKDIR /vm

COPY sandbox.c .
RUN gcc -fstack-protector-strong -D_FORTIFY_SOURCE=2 -pie -fPIE -Wl,-z,relro,-z,now -Wl,-z,noexecstack -fcf-protection=full sandbox.c -o sandbox -lcrypt

RUN wget -O debian.qcow2 https://cdimage.debian.org/images/cloud/bookworm/20250316-2053/debian-12-generic-amd64-20250316-2053.qcow2

COPY flag.txt .
RUN virt-copy-in -a debian.qcow2 sandbox flag.txt /root/ && \
    virt-customize -a debian.qcow2 --install socat,gcc && \
    virt-customize -a debian.qcow2 --run-command "systemctl disable ssh; systemctl mask systemd-networkd-wait-online; echo \"socat TCP-LISTEN:1337,reuseaddr,fork EXEC:/root/sandbox,stderr &\" >> /root/.bashrc"

COPY user-data.yaml .
COPY metadata.yaml .
RUN cloud-localds seed.img user-data.yaml metadata.yaml

COPY start.sh .
RUN chmod +x start.sh

FROM pwn.red/jail@sha256:ee52ad5fd6cfed7fd8ea30b09792a6656045dd015f9bef4edbbfa2c6e672c28c

COPY --from=app / /srv
RUN rm -r /srv/var/tmp && ln -s /tmp /srv/var/tmp && mkdir /srv/app && ln -s /vm/start.sh /srv/app/run
ENV JAIL_POW=45000 JAIL_TMP_SIZE=68719476736 JAIL_TIME=0 JAIL_PIDS=0 JAIL_MEM=0 JAIL_CPU=0
