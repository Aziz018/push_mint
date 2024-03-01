CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = push_swap
NAME_BONUS = checker
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
SRCS = check_args.c creat_stack.c operations.c push.c reverse_rotate.c rotate.c sort.c swap.c push_swap.c read_input.c is_sorted.c check_errors.c
SRCS_BONUS = checker_bonus.c check_args.c creat_stack.c operations.c push.c reverse_rotate.c rotate.c swap.c read_input.c is_sorted.c check_errors.c
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
	$(RM) $(OBJS)
	make -C ./libft clean
	make -C ./ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(RM) checker
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all

.SECONDARY: