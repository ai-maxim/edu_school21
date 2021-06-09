
From debian:buster

EXPOSE 443

LABEL maintainer="inception - qdong@student.21-school.ru"

RUN apt-get update && apt-get -y install nginx
RUN apt-get install openssl

COPY site.conf /etc/nginx/sites-available/
COPY index.html /var/www/html/
COPY ./start.sh /

RUN chmod +x start.sh
RUN chmod -R 755 /etc/ssl/*
RUN chmod -R 755 /var/www/*

ENTRYPOINT /start.sh
