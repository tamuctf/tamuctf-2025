#!/bin/sh

setfacl -m u:latex:rX /tmp
setfacl -d -m u:latex:rX /tmp
setfacl -m u:latex:000 /dev/shm
setfacl -d -m o:rwX /var/tmp

export SERVER_KEY=$(openssl rand -hex 32)

./maintenance.sh &
php-fpm -D
nginx
