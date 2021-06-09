#!/bin/bash

ln -s /etc/nginx/sites-available/site.conf /etc/nginx/sites-enabled/nginx.conf
nginx -g "daemon off;"
