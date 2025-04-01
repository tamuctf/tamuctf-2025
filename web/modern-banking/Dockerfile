FROM debian:bookworm-slim

ARG port

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y curl fcgiwrap gcc libdb-dev libgmp-dev lzip make nginx

WORKDIR /banking

RUN cd /tmp && \
    curl -L -O https://deac-riga.dl.sourceforge.net/project/gnucobol/gnucobol/3.2/gnucobol-3.2.tar.lz && \
    tar -xf gnucobol-3.2.tar.lz && \
    cd gnucobol-3.2 && \
    ./configure && \
    make && \
    make install && \
    ln -s /usr/local/lib/libcob.so.4 /usr/lib

COPY ./banking.cob /tmp
RUN cd /tmp && \
    cobc -x banking.cob && \
    mkdir -p /var/www/localhost/index.cgi && \
    cp banking /var/www/localhost/index.cgi && \
    cp banking /usr/local/bin/banking.cgi && \
    echo 'COB_LS_VALIDATE=false' > /usr/local/share/gnucobol/config/runtime.cfg

COPY ./default.conf /etc/nginx/sites-available/default
RUN sed -i "s/PORT/$port/g" /etc/nginx/sites-available/default

RUN mkdir -p /var/banking

COPY ./entry.sh /banking

ENV PORT=$port
ENV PASS=zmA0ZvOZFNvvEmsN2mKbnHeFD1w
ENV SECRET=UCfD56TkGK4SDCoQAvTOpGrFlrQ
ENV FLAG=gigem{C08OL_W45_N0ugHt_1MmuN3}
ENTRYPOINT [ "sh" ]

CMD [ "entry.sh" ]
