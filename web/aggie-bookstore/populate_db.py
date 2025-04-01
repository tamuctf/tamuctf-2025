from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017/")
db = client['aggie_bookstore']
books_collection = db['books']

books_collection.delete_many({})

books_data = [
    {
        "title": "The Lost Book of Secrets",
        "author": "John Doe",
        "genre": "Mystery",
        "description": "This is a secret description for the Lost Book of Secrets."
    },
    {
        "title": "A Study in Scarlet",
        "author": "Arthur Conan Doyle",
        "genre": "Mystery",
        "description": "A classic Sherlock Holmes detective story."
    },
    {
        "title": "The Adventures of Huckleberry Finn",
        "author": "Mark Twain",
        "genre": "Adventure",
        "description": "An adventure on the Mississippi River."
    },
    {
        "title": "1984",
        "author": "George Orwell",
        "genre": "Dystopian",
        "description": "A dystopian novel about totalitarian regime and surveillance."
    },
    {
        "title": "Brave New World",
        "author": "Aldous Huxley",
        "genre": "Dystopian",  
        "description": "Set in a futuristic world, a dystopian society."
    },
    {
        "title": "Treasure Island",
        "author": "Robert Louis Stevenson",
        "genre": "Adventure",
        "description": "A swashbuckling tale of pirates and treasure."
    },
    {
        "title": "Internal Manual",
        "author": "System",
        "genre": "Manual",
        "type": "internal",
        "description": "This manual is not meant for public access."
    },
    {
        "title": "Admin Operations Guide",
        "author": "SysAdmin",
        "genre": "Manual",
        "type": "internal",
        "internal_notes": "Root password: hunter2",
        "description": "Contains system-level procedures and fallback commands."
    },
    {
        "title": "Test Entry - Ignore",
        "author": "QA Bot",
        "genre": "junk",
        "type": "test",
        "description": "This is just a test entry."
    },
    {
        "title": "FLAG{nosql_n0_pr0bl3m}",
        "author": "admin",
        "genre": "Secret",
        "type": "lmao",
        "description": "You shouldn't see this"
    }

]

books_collection.insert_many(books_data)
print("Database populated with sample and hidden/internal books.")
