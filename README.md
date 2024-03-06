# push_mint

for check leaks:
    valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17"

for check your program:
    args=$(seq -500 500 | shuf -n 100 | tr '\n' ' '); ./push_swap $args | ./checker_linux $args; echo $args