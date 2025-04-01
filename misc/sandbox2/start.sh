#!/bin/sh

while true; do
  port=$(shuf -n 1 -i 5000-5999)
  timeout 1 nc -l -n "$port"
  if [ $? -eq 124 ]; then
    break
  fi
done

qemu-system-x86_64 -m 512 \
  -drive if=virtio,file=/vm/debian.qcow2,format=qcow2,snapshot=on \
  -drive if=virtio,file=/vm/seed.img,format=raw,snapshot=on \
  -netdev user,id=net0,hostfwd=tcp::${port}-:1337 \
  -device virtio-net,netdev=net0 \
  -display none &

echo "Please wait a minute for the QEMU VM to start..."
sleep 60
echo
socat - TCP:127.0.0.1:$port

while true; do
    echo
    echo -n "Disconnected from socket. Try reconnecting? (y/n): "
    read answer
    case "$answer" in
        [Yy]) echo; socat - TCP:127.0.0.1:$port ;;
        [Nn]) exit ;;
    esac
done