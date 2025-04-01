#!/bin/bash

head -n 1

sleep 5

echo 'base64 -d <<"END_OF_POC" | xzcat > switcher.c'
xz -c -e switcher.c | base64 | pv -q -L 256
echo 'END_OF_POC'

echo 'base64 -d <<"END_OF_POC" | xzcat > poc.sh'
xz -c -e poc.sh | base64 | pv -q -L 256
echo 'END_OF_POC'

echo chmod +x poc.sh
echo ./poc.sh

cat -
