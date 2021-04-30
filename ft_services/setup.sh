#!/usr/bin/env bash

minikube start

eval $(minikube docker-env)

docker build -t nginx srcs/nginx
