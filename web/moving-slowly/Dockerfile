FROM ubuntu:24.04

ARG port

RUN apt-get update -y && \
    apt-get install -y python3-pip python3 curl wget

WORKDIR /app

RUN pip3 install --break-system-packages flask transformers==4.47.1 && \
    pip3 install --break-system-packages torch --index-url https://download.pytorch.org/whl/cpu

ENV TRANSFORMERS_CACHE=/tmp/huggingface
RUN mkdir -p /tmp/huggingface

COPY ./app /app

RUN chmod 555 /app
RUN chmod -R 555 /app/templates

ENV PORT=$port
ENV PASS=supers3cur3123
ENV FLAG=gigem{m4yb3_n0t_everything_needs_ai}
ENTRYPOINT [ "python3" ]

CMD [ "app.py" ]