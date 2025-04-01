# Research

Author: `cobra`

My professor made a website to compile LaTeX for his research. Everything is securely stored with encryption, but I wonder if there's still a way to get access to what he's working on...

Note: The challenge is reset every 5 minutes to ensure stability.

## Solution

Since the admin user has an active PHP session, we can read the admin session file in `/tmp`. However, there are two issues: all data in the session is encrypted with the server key and we need to figure out how to list files to actually find the session.

By default, `pdflatex` runs with `shell_escape` set to partial which includes a predefiend list of commands that LaTeX is allowed to run. Since the server is running Arch, we can install `pdflatex` in a local Arch environment and see which commands are allowed in the version of TeX Live it uses. All commands are listed in `/usr/share/texmf-dist/web2c/texmf.cnf`. Notably, the `kpsewhich`, `l3sys-query`, and `texosquery-jre8` commands are useful, but `texosquery-jre8` requires Java which isn't installed.

We can use `kpsewhich` to read environment variables including the `SERVER_KEY` variable.

```latex
\usepackage{verbatim}
\verbatiminput{|kpsewhich --var-value SERVER_KEY}
```

We can use `l3sys-query` to list files.

```latex
\usepackage{verbatim}
\verbatiminput{|l3sys-query ls}
```

Once we know the file path, we can read the session (after applying some formatting so it fits in the PDF) and decrypt it with the server key.

## Unintended Solution

Instead of decrypting the admin session data, we can just copy the PHP session ID from the file name and use it to gain access to the admin session.

flag:
`gigem{i_hate_latex_after_writing_this_challenge}`
