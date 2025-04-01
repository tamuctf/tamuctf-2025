from flask import Flask, request, session, render_template, redirect, url_for
import json
from base64 import b64encode, b64decode
from crypto import sign, verify, public_key
import os
import secrets
from functools import wraps

app = Flask(__name__)
app.secret_key = os.urandom(32)

flag = os.getenv("FLAG", "gigem{test_flag}")

def encode_session(username):
    data = {
        "username": username,
        "signature": b64encode(sign(username.encode())).decode()
    }
    return b64encode(json.dumps(data).encode()).decode()

def decode_session(data):
    try:
        data = json.loads(b64decode(data).decode())
        return data
    except:
        return None
    
DEFAULT_SESSION = encode_session("guest")

def check_session(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        # reset cookie response
        response = redirect(url_for("index"))
        response.set_cookie("smelter-session", DEFAULT_SESSION)

        _session = request.cookies.get("smelter-session")
        if not _session:
            return response
        
        data = decode_session(_session)
        if not data:
            return response
        
        username, signature = data.get("username"), data.get("signature")
        if not username or not signature:
            return response
        
        if not verify(username.encode(), b64decode(signature)):
            return response
        
        session["username"] = data["username"]
        return f(*args, **kwargs)
    
    return decorated_function

# Endpoints
@app.route("/")
@check_session
def index():
    if "username" not in session:
        response = redirect(url_for("login"))
        response.set_cookie("smelter-session", DEFAULT_SESSION)
        return response

    username = session["username"]
    if username == "admin":
        return render_template("index.html", username=username, public_key=public_key(), flag=flag)
    return render_template("index.html", username=username, public_key=public_key())

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)