CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
NAME = push_swap
NAME_BONUS = checker
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
SRCS = push_swap.c \
		check_args.c \
		creat_stack.c \
		ft_clean.c \
		help_functions1.c \
		help_functions2.c \
		is_sorted.c \
		operations.c \
		print_args.c \
		push.c \
		read_input.c \
		reverse_rotate.c \
		rotate.c \
		sort.c \
		stage1.c \
		stage2.c \
		swap.c \

SRCS_BONUS = checker_bonus.c \
			check_args.c \
			creat_stack.c \
			operations.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			read_input.c \
			is_sorted.c \
			ft_clean.c \
			check_errors_bonus.c \
			help_functions1.c \
			help_functions2.c \
			
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	make -C ./libft
	make bonus -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f checker
	make fclean -C ./libft
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean