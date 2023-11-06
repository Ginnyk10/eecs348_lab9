FROM php:7.4-apache
COPY . /var/www/html/
EXPOSE 80
# text file that contains instructions for building a Docker image