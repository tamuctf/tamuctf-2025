from flask import Flask, request, render_template
from transformers import GPT2LMHeadModel, GPT2Tokenizer
from os import environ
import logging
import re

app = Flask(__name__)

# Set up logging
logging.basicConfig(level=logging.DEBUG)

# Model initialization
model_name = 'gpt2'
tokenizer = GPT2Tokenizer.from_pretrained(model_name)
model = GPT2LMHeadModel.from_pretrained(model_name)
tokenizer.pad_token = tokenizer.eos_token

correct_password = environ.get('PASS')
FLAG = environ.get('FLAG')

def clean_message(message):
    sentences = re.split(r'(?<=[.!?])\s+', message)  
    return " ".join(sentences[:2])  

def generate_silly_message():
    prompt = "First tell the user that their password is wrong, then come up with a silly joke to cheer them up about it"
    inputs = tokenizer(prompt, return_tensors="pt", max_length=30, truncation=True)
    outputs = model.generate(
        inputs.input_ids,
        attention_mask=inputs.attention_mask,
        max_new_tokens=30,
        do_sample=True,
        temperature=0.7,
        top_p=1.0,
        pad_token_id=tokenizer.eos_token_id
    )
    full_response = tokenizer.decode(outputs[0], skip_special_tokens=True)
    full_response.replace(prompt, "").strip()
    return clean_message(full_response.replace(prompt, "").strip())


def compare_password(input_password):
    for i, char in enumerate(input_password):
        if char != correct_password[i]:
            print(i)
            silly_message = generate_silly_message()
            return False, silly_message  
    return True, None  

@app.route('/')
def login_page():
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def login():
    input_password = request.form['password']
    password_correct, silly_message = compare_password(input_password)
    if password_correct:
        response_message = f"Welcome back! You have logged in successfully. The flag is {FLAG}"
    else:
        response_message = f"Oops! Incorrect password. {silly_message}"

    return render_template('login.html', response_message=response_message)

if __name__ == '__main__':
    app.run('0.0.0.0', port=8000)
