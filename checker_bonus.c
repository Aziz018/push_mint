/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:04 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 17:40:07 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		ft_perror("Error");
}

void	push(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strstr(move, "pa"))
		push_a(stack_a, stack_b, "bonus");
	else if (ft_strstr(move, "pb"))
		push_b(stack_a, stack_b, "bonus");
	else
		ft_perror("Error");
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
	else
		ft_perror("Error");
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
	else
		ft_perror("Error");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arrr;
	char	**arr;
	char	*str;

	if (ac < 2)
		return (0);
	arr = read_input(ac, av);
	str = arry_to_str(ac, arr);
	arrr = ft_split(str, ' ');
	if (!arrr)
	{
		free_all(str, arr, arrr);
		ft_perror("split fail");
	}
	check_args(arrr, arr, str);
	free_all(str, arr, arrr);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	main_continue(stack_a, stack_b, ac, av);
}
