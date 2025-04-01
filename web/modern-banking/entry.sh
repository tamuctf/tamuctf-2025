#!/bin/sh

port=$PORT

/usr/sbin/nginx
rm -f /var/run/fcgiwrap.socket
nohup /usr/sbin/fcgiwrap -f -s unix:/var/run/fcgiwrap.socket &
sleep 1
chmod a+rw /var/run/fcgiwrap.socket
chmod -R a+rx /var/www

while true; do
    echo "Port: $port"
    curl -s "localhost:$port?page=register" --data-raw "action=register&username=administrator&password=$PASS" >/dev/null
    cookie="$(curl -v "localhost:$port?page=login" --data-raw "action=login&username=administrator&password=$PASS" 2>&1 | grep Set-Cookie | cut -d' ' -f3)"
    account="$(curl "localhost:$port?page=home" -b "$cookie" | grep "<tr><td>" | head -n1 | cut -d'>' -f3)"
    if [ -z "$account" ]; then
        curl -s "localhost:$port?page=manage" -b "$cookie" --data-raw "action=new" >/dev/null
    fi
    curl -s "localhost:$port?page=admin" -b "$cookie" --data-raw "action=refresh&account=1&secret=$SECRET" >/dev/null
    curl -s "localhost:$port?page=batch" -b "$cookie" --data-raw "action=batch&secret=$SECRET"
    sleep 20
done
