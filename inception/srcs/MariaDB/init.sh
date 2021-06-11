#!bin/bash
# Configure a wordpress database
service mysql start
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "CREATE USER 'mix'@'%' IDENTIFIED BY 'aq';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'mix'@'%' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
mysql -u root wordpress < /var/www/damp_db.sql
#cat /var/www/damp_db.sql | mysql -u root --skip-password -p wordpress
service mysql stop
