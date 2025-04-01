from flask import Flask, request, render_template

app = Flask(__name__, subdomain_matching=True)
app.config['SERVER_NAME'] = 'transparency.cybr.club'

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/create')
def create():
    return render_template('create.html')

@app.route('/', subdomain='g64aes8z')
def example():
    return render_template('example.html')

@app.route('/', subdomain='tve987yv')
def flag():
    return render_template('flag.html')


if __name__ == "__main__":
    app.run("0.0.0.0", 3000)
