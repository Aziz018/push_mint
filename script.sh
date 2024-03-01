#!/bin/sh

make fclean

read -p "Do you want to push changes to GitHub? (y/n): " confirm
if [ "$confirm" = "y" ]; then
    git add .
    echo "enter your msg"
    # read msg
    git commit -m "push_swap"
    git push origin main -f
else
    echo "No changes were pushed to GitHub."
fi