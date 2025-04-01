from flask import Flask, request, render_template, jsonify
from pymongo import MongoClient
import re

app = Flask(__name__)

client = MongoClient("mongodb://localhost:27017/")
db = client['aggie_bookstore']
books_collection = db['books']

def sanitize(input_str: str) -> str:
    return re.sub(r'[^a-zA-Z0-9\s]', '', input_str)

@app.route('/')
def index():
    return render_template('index.html', books=None)

@app.route('/search', methods=['GET', 'POST'])
def search():
    query = {"$and": []}
    books = []

    if request.method == 'GET':
        title = request.args.get('title', '').strip()
        author = request.args.get('author', '').strip()

        title_clean = sanitize(title)
        author_clean = sanitize(author)

        if title_clean:
            query["$and"].append({"title": {"$eq": title_clean}})  

        if author_clean:
            query["$and"].append({"author": {"$eq": author_clean}}) 

        if query["$and"]:
            books = list(books_collection.find(query))


        return render_template('index.html', books=books)

    elif request.method == 'POST':
        if request.content_type == 'application/json':
            try:
                data = request.get_json(force=True)

                title = data.get("title")
                author = data.get("author")
                if isinstance(title, str):
                    title = sanitize(title)
                    query["$and"].append({"title": title})
                elif isinstance(title, dict):
                    query["$and"].append({"title": title})

                if isinstance(author, str):
                    author = sanitize(author)
                    query["$and"].append({"author": author})
                elif isinstance(author, dict):
                    query["$and"].append({"author": author})

                if query["$and"]:
                    books = list(books_collection.find(query))
                    return jsonify([
                        {"title": b.get("title"), "author": b.get("author")} for b in books
                    ])

                return jsonify({"error": "Empty query"}), 400

            except Exception as e:
                return jsonify({"error": str(e)}), 500

        return jsonify({"error": "Unsupported Content-Type"}), 400
    
if __name__ == "__main__":
    app.run("0.0.0.0", 8000)
