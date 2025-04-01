FROM ubuntu:22.04

RUN apt-get update -y && \
    apt-get install -y python3

WORKDIR /

COPY index.html /index.html
COPY impossible_ctf.swf /impossible_ctf.swf

USER 1000:1000

ENTRYPOINT [ "python3", "-m", "http.server", "3000" ]
