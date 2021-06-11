
From debian:buster

EXPOSE 443

LABEL maintainer="inception - qdong@student.21-school.ru"

RUN apt-get update && apt-get -y install nginx
RUN apt-get install openssl

COPY site.conf /etc/nginx/sites-available/
#COPY index.html /var/www/html/
COPY ./start.sh /
COPY ./openssl ./openssl

RUN chmod 444 ./openssl/localhost.crt
RUN chmod 444 ./openssl/localhost.key
RUN chmod +x start.sh
RUN chmod -R 755 /etc/ssl/*
RUN chown -R www-data:www-data /var/www/html
RUN chmod -R 755 /var/www/html

ENTRYPOINT /start.sh
