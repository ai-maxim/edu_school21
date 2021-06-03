From debian:buster

EXPOSE 443

LABEL maintainer="inception - qdong@student.21-school.ru"

RUN apt-get update && apt-get -y install nginx
RUN apt-get install openssl

# RUN mkdir /etc/ssl

COPY nginx.conf /etc/nginx/sites-available/default
COPY index.html /var/www/html/

RUN chown -R www-data /etc/ssl/*
RUN chown -R www-data /var/www/*

COPY ./run.sh /opt/run.sh

CMD ["/opt/run.sh"]
