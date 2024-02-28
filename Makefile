CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
NAME = push_swap
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
SRCS = check_args.c creat_stack.c operations.c push.c reverse_rotate.c rotate.c sort.c swap.c push_swap.c read_input.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C ./libft
	make bonus -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C ./libft clean
	make -C ./ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all