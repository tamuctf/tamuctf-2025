FROM pwn.red/jail

COPY --from=python:3.12-slim-bookworm / /srv
COPY --chmod=755 chall.py /srv/app/run
COPY flag.txt /srv/app/flag.txt

ENV JAIL_POW=15000 JAIL_TIME=600 JAIL_TIME=0 JAIL_PIDS=0 JAIL_MEM=0 JAIL_CPU=0