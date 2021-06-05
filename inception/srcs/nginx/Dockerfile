
From debian:buster

EXPOSE 443

LABEL maintainer="inception - qdong@student.21-school.ru"

RUN apt-get update && apt-get -y install nginx
RUN apt-get install openssl

COPY site.conf /etc/nginx/sites-available/
COPY index.html /var/www/html/
COPY ./start.sh /

RUN chmod +x start.sh
RUN chmod 777 /etc/ssl/*
RUN chmod 777 /var/www/*

#SHELL ["/bin/bash"]
#CMD ["ln", "-s", "/etc/nginx/sites-available/site.conf", "/etc/nginx/sites-enabled/site.conf"]

ENTRYPOINT /start.sh
