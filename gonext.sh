##! /bin/bash

read -p "Enter the new file locatio: " filepath

sudo mkdir $filepath
cd $filepath
sudo chown -R pacria .
code .
