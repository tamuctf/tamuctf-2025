#!/bin/sh

flag_tex=$(cat flag.tex)

sleep 15

while true; do
    rm -f session.txt
    rm -rf /var/tmp/*
    rm -rf /tmp/*
    
    curl -s -c session.txt -X POST http://localhost:8000/update.php --data-urlencode "latex=$flag_tex"
    curl -s -o /dev/null -b session.txt http://localhost:8000/compile.php
    sleep 300
done
