FROM ubuntu:22.04 AS build-base

# because, for some reason, installers need to be interactive
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

RUN sed -i 's/# deb-src/deb-src/g' /etc/apt/sources.list
RUN apt update && \
    apt -y --autoremove full-upgrade && \
    apt -y --autoremove install musl-tools build-essential git curl wget software-properties-common gnupg && \
    apt -y --autoremove install $(apt list linux-tools-*-generic | sort | tail -n 1 | cut -d'/' -f1) && \
    bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)" && \
    apt -y build-dep linux

FROM build-base AS build-linux

# Linux is too large
RUN git config --global http.postBuffer 524288000
RUN git config --global https.postBuffer 524288000

RUN cd /opt && \
    git clone --branch v6.7 --depth 1 https://github.com/torvalds/linux.git

ADD linux.config /opt/linux/.config
RUN cd /opt/linux && \
    make -j$(nproc) bzImage vmlinux

FROM build-base AS build-busybox

RUN cd /opt && \
    curl https://www.busybox.net/downloads/busybox-1.36.1.tar.bz2 | tar xjv

ADD busybox.config /opt/busybox-1.36.1/.config
RUN cd /opt/busybox-1.36.1 && \
    make -j$(nproc) && make install && \
    mkdir -p /opt/rootfs && cd /opt/rootfs && \
    mkdir -p bin sbin etc proc sys usr/bin usr/sbin && \
    cp -a /opt/busybox-1.36.1/_install/* .

FROM build-base AS build-rust

RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y --default-toolchain nightly
RUN . $HOME/.cargo/env && \
    rustup target add x86_64-unknown-linux-musl && \
    rustup component add rust-src && \
    cargo install --force --git https://github.com/aya-rs/bpf-linker && \
    cargo install --force bindgen-cli && \
    cargo install --force --git https://github.com/aya-rs/aya aya-tool

ADD src /opt/call-logger
COPY --from=build-linux /opt/linux/vmlinux /opt/linux/vmlinux
RUN . $HOME/.cargo/env && \
    export PATH=$(find /usr/lib/linux-tools -maxdepth 1 | paste -sd':'):$PATH && \
    echo $PATH && \
    aya-tool generate --btf /opt/linux/vmlinux task_struct dentry > /opt/call-logger/call-logger-ebpf/src/binding.rs

RUN . $HOME/.cargo/env && \
    cd /opt/call-logger && \
    cargo build --release --target x86_64-unknown-linux-musl

FROM build-base AS build

COPY --from=build-busybox /opt/rootfs /opt/rootfs

COPY --from=build-rust /opt/call-logger/target/x86_64-unknown-linux-musl/release/call-logger /opt/rootfs/sbin/call-logger
RUN chmod u+s /opt/rootfs/sbin/call-logger

ADD read-any-file.c /opt/read-any-file.c
RUN musl-gcc -static /opt/read-any-file.c -o /opt/rootfs/sbin/read-any-file
RUN chmod u+s /opt/rootfs/sbin/read-any-file

ADD init /opt/rootfs/init

RUN cd /opt/rootfs && \
    find . -print0 | cpio --null -ov --format=newc | gzip -9 > /opt/initramfs.cpio.gz

FROM alpine:latest AS app

RUN apk add --no-cache qemu-system-x86_64 socat
ADD entrypoint.sh /bin/entrypoint.sh

COPY --from=build /opt/initramfs.cpio.gz /opt/initramfs.cpio.gz
COPY --from=build-linux /opt/linux/arch/x86/boot/bzImage /opt/bzImage
ADD flag.txt /opt/flag.txt

FROM pwn.red/jail

COPY --from=app / /srv
COPY --from=build /opt/rootfs/sbin/call-logger /call-logger
COPY --from=build /opt/rootfs/sbin/read-any-file /read-any-file

RUN rm -r /srv/var/tmp && ln -s /tmp /srv/var/tmp && mkdir /srv/app && ln -s /bin/entrypoint.sh /srv/app/run

ARG shell_port
ENV JAIL_PORT=${shell_port} JAIL_POW=45000 JAIL_TMP_SIZE=1342177280 JAIL_DEV=null,zero,urandom JAIL_PIDS=0 JAIL_TIME=0 JAIL_MEM=0 JAIL_CPU=0
