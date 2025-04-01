# Moving Slowly

Author: `moveslow`

Everyone's been talking about how AI is the future and will be in everything so I added AI to my login panel!

Note: The password is alphanumeric.

## Dev Notes

Timing attack

Challenge takes a minute to start up

## Solution

Looking at the source code, the server checks the password character by character. If a character is incorrect, it uses GPT-2 to generate a silly message which takes a signifant amount of time. Because of this, we can easily perform a timing attack to bruteforce the password character by character. 

flag:
`gigem{m4yb3_n0t_everything_needs_ai}`