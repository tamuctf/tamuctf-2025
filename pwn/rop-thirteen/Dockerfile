FROM debian:buster-slim as build

ARG name

RUN apt-get update -y; apt-get install build-essential -y
ADD $name.go /tmp/$name.go
ADD Makefile /tmp/Makefile

RUN apt-get install wget -y; wget https://go.dev/dl/go1.20.6.linux-amd64.tar.gz -O /tmp/go1.20.6.linux-amd64.tar.gz; tar -C /usr/local -xzf /tmp/go1.20.6.linux-amd64.tar.gz;
RUN apt-get remove wget -y
RUN apt-get install python3 -y

RUN cd /tmp/; export PATH=$PATH:/usr/local/go/bin; make all

RUN rm -rf /usr/local/go

FROM debian:buster-slim

ARG name
ARG port

RUN apt-get update -y; apt-get install socat -y
COPY --from=build /tmp/$name /pwn/$name
COPY flag.txt /pwn/flag.txt
WORKDIR /pwn

EXPOSE $port

RUN echo "exec socat -s TCP-LISTEN:$port,reuseaddr,fork EXEC:'timeout -k 1 60 /pwn/$name,stderr'" > /pwn/docker_entrypoint.sh

ENTRYPOINT ["sh", "/pwn/docker_entrypoint.sh"]
