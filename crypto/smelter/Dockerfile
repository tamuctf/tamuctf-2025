FROM python:3.11-alpine

RUN pip3 install --break-system-packages Flask pycryptodome pyasn1

ARG flag
ENV FLAG=${flag}
COPY src/ /app

ENTRYPOINT ["python3", "/app/main.py"]