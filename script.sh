#!/bin/sh

make re
make clean

read -p "Do you want to push changes to GitHub? (y/n): " confirm
if [ "$confirm" = "y" ]; then
    git add .
    echo "enter your msg"
    read msg
    git commit -m $msg
    git push origin main 
else
    echo "No changes were pushed to GitHub."
fi