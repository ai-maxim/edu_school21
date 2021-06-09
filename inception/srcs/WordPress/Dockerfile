FROM debian:buster
EXPOSE 9000

RUN apt-get update

RUN mkdir -p /var/run/php/

RUN apt-get install -y php-fpm php-mysql php-xml php-mbstring php-gd wget curl

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz

ENTRYPOINT ["/usr/sbin/php-fpm7.3"]
CMD ["--nodaemonize"]
