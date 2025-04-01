FROM ubuntu:22.04

RUN apt-get update -y && \
    apt-get install -y python3-pip python3-dev

WORKDIR /

COPY app.py /app.py
COPY templates /templates

RUN pip3 install flask

USER 1000:1000

ENTRYPOINT [ "python3" ]

CMD [ "app.py" ]
