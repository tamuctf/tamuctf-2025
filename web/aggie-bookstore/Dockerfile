FROM ubuntu:24.04

RUN apt-get update -y && \
    apt-get install -y python3-pip python3-dev gnupg curl libc6 libcurl4 libssl3


RUN curl -fsSL https://www.mongodb.org/static/pgp/server-8.0.asc | gpg -o /usr/share/keyrings/mongodb-server-8.0.gpg --dearmor

RUN echo "deb [ arch=amd64,arm64 signed-by=/usr/share/keyrings/mongodb-server-8.0.gpg ] https://repo.mongodb.org/apt/ubuntu noble/mongodb-org/8.0 multiverse" | tee /etc/apt/sources.list.d/mongodb-org-8.0.list

RUN apt-get update -y


RUN apt-get install -y --no-install-recommends mongodb-org

RUN chmod 1777 /tmp
RUN mkdir -p /data/db


EXPOSE 27017

WORKDIR /

COPY app.py /app.py
COPY templates /templates
COPY static /static
COPY populate_db.py /populate_db.py

RUN apt install python3-flask python3-pymongo -y

CMD mongod --bind_ip_all --logpath /data/db/mongodb.log --fork && python3 populate_db.py && python3 app.py

