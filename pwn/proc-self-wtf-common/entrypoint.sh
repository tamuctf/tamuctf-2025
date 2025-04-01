#!/bin/sh

set -m

cleanup() {
  trap "" INT TERM EXIT
  kill -9 "${pid}" 2>/dev/null || true
  rm -rf "${socks}"
  exit 0
}

socks="$(mktemp -d)"
trap cleanup INT TERM EXIT

qemu-system-x86_64 -kernel /opt/bzImage -initrd /opt/initramfs.img.lz4 -append "earlyprintk=serial,ttyS0 console=ttyS0" -drive "file=/opt/disk.img,format=raw,snapshot=on" -drive "file=/opt/crontab,format=raw,snapshot=on" -drive "file=/opt/flag.txt,format=raw,snapshot=on" -monitor none -display none -serial unix:"${socks}/entrypoint",server -m 256M -accel kvm &
export pid=$!

sleep .5
while ! socat -s - unix-connect:"${socks}/entrypoint"; do
  sleep .5
done
