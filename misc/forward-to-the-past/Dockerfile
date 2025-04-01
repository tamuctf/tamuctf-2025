FROM ubuntu:22.04 AS build

ARG name

RUN apt-get update -y && apt-get install -y build-essential
COPY forward-to-the-past.c /tmp/forward-to-the-past.c
COPY db.c /tmp/db.c
COPY Makefile /tmp/Makefile
RUN cd /tmp/; make all

FROM ubuntu:22.04

ARG name
ARG port

RUN apt-get update -y && apt-get install -y socat
COPY --from=build /tmp/forward-to-the-past /forward-to-the-past
WORKDIR /

EXPOSE $port

RUN echo "exec socat -s TCP-LISTEN:$port,reuseaddr,fork EXEC:'timeout -k 1 60 /forward-to-the-past,pty,raw,echo=0'" > /docker_entrypoint.sh

ENTRYPOINT ["sh", "/docker_entrypoint.sh"]
