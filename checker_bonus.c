#include "push_swap.h"

int	ft_strstr(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\n' || str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\n' && str2[i] == '\0')
		return (1);
	return (0);
}

void	swap(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strstr(move, "sa"))
		swap_a(stack_a, "bonus");
	else if (ft_strstr(move, "sb"))
		swap_b(stack_b, "bonus");
	else if (ft_strstr(move, "ss"))
	{
		swap_a(stack_a, "bonus");
		swap_b(stack_b, "bonus");
	}
}
void	push(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strstr(move, "pa"))
		push_a(stack_a, stack_b, "bonus");
	else if (ft_strstr(move, "pb"))
		push_b(stack_a, stack_b, "bonus");
}

void	rotate(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strstr(move, "ra"))
		rotate_a(stack_a, "bonus");
	else if (ft_strstr(move, "rb"))
		rotate_b(stack_b, "bonus");
	else if (ft_strstr(move, "rr"))
	{
		rotate_a(stack_a, "bonus");
		rotate_b(stack_b, "bonus");
	}
}

void	reverse_rotate(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strstr(move, "rra"))
		reverse_rotate_a(stack_a, "bonus");
	else if (ft_strstr(move, "rrb"))
		reverse_rotate_b(stack_b, "bonus");
	else if (ft_strstr(move, "rrr"))
	{
		reverse_rotate_a(stack_a, "bonus");
		reverse_rotate_b(stack_b, "bonus");
	}
}

void	which_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (move[0] == 's' && ft_strlen(move) == 3)
		swap(move, stack_a, stack_b);
	else if (move[0] == 'p' && ft_strlen(move) == 3)
		push(move, stack_a, stack_b);
	else if (move[0] == 'r' && ft_strlen(move) == 3)
		rotate(move, stack_a, stack_b);
	else if (move[0] == 'r' && move[1] == 'r' && ft_strlen(move) == 4)
		reverse_rotate(move, stack_a, stack_b);
	else
	{
		ft_printf("Error");
		exit(1);
	}
}

void	check_moves(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		which_move(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char **av)
{
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arr;
	char	**arrr;

	if (ac < 2)
		return (0);
	arr = read_input(ac, av);
	str = arry_to_str(ac, arr);
	arrr = ft_split(str, ' ');
	check_args(arrr);
	free_all(str, arr, arrr);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	creat_stack(stack_a, ac, av);
	check_moves(stack_a, stack_b);
	if (is_empty(stack_a) || !is_empty(stack_b))
	{
		clear_stacks(stack_a, stack_b);
		ft_perror("Error");
	}
	if (!is_sorted(stack_a))
		ft_printf("KO");
	else
		ft_printf("Ok");
	clear_stacks(stack_a, stack_b);
}
