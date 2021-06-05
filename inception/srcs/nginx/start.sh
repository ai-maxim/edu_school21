#!/bin/bash
ln -s /etc/nginx/sites-available/site.conf /etc/nginx/sites-enabled/site.conf
nginx -g "daemon off;"
