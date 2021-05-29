From alpine:3.12

EXPOSE 80 443

# VOLUME /var/run/docker.sock:/var/run/docker.sock

# Installation
RUN apk update && apk add mariadb mariadb-client && apk add --no-cache --upgrade bash \
&& rm -rf /var/cache/apk/*

# Copy initialisation script
COPY ./init_docker.sh .
COPY ./init_mysql.sh .
COPY wp.sql .

# Add permission
RUN chmod 777 init_docker.sh && chmod 777 init_mysql.sh

# Start configuration script
ENTRYPOINT [ "./init_docker.sh" ]

# docker build -t nginx .
# docker run -it --rm -p 80:80 -p 443:443 nginx
# cd /etc/nginx/sites-available# cat default
