FROM node:alpine@sha256:6eae672406a2bc8ed93eab6f9f76a02eb247e06ba82b2f5032c0a4ae07e825ba AS builder

WORKDIR /app
COPY editor/editor.js editor/package.json ./

RUN npm install && \
    mkdir dist && \
    npx rollup editor.js -f iife -o dist/cm6.bundle.js -p @rollup/plugin-node-resolve -n cm6 && \
    npx minify dist/cm6.bundle.js > dist/cm6.bundle.min.js

FROM archlinux@sha256:8da7c82c2d6b22c06d1e36e10267ac632f72c7e4a6e0c7d9801f44771e163ac5

ARG port

RUN pacman -Syu --noconfirm nginx php php-fpm texlive acl curl composer
RUN mkdir -p /var/www/html && \
    chown http:http /var/www/html && \
    curl -o /etc/php/php.ini https://raw.githubusercontent.com/php/php-src/refs/heads/PHP-8.4.5/php.ini-production && \
    echo 'session.save_path = "0;644;/tmp"' >> /etc/php/php.ini && \ 
    echo 'env[PATH] = /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin' >> /etc/php/php-fpm.d/www.conf && \
    echo 'env[SERVER_KEY] = $SERVER_KEY' >> /etc/php/php-fpm.d/www.conf  && \
    useradd -d /nonexistent -r -s /usr/sbin/nologin latex && \
    chown latex /usr/bin/pdftex && \
    chmod u+s /usr/bin/pdftex

COPY nginx.conf /etc/nginx/
RUN sed -i "s/listen 8000/listen ${port}/" /etc/nginx/nginx.conf

WORKDIR /var/www/html
COPY --chown=http:http src/ .
RUN composer install
COPY --from=builder /app/dist/cm6.bundle.min.js static/

EXPOSE ${port}

WORKDIR /root
COPY start.sh maintenance.sh flag.tex ./
RUN chmod +x start.sh && \
    chmod +x maintenance.sh
CMD ["/root/start.sh"]
