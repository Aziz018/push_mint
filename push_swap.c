/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:23:14 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/03 21:23:16 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void clean_all(t_stack *stack_a, t_stack *stack_b)
{
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arr;
	char	*str;
	char	**arrr;

	arr = read_input(ac, av);
	str = arry_to_str(ac, arr);
	arrr = ft_split(str, ' ');
	check_args(arrr, arr, str);
	free_all(str, arr, arrr);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	creat_stack(stack_a, ac, av);
	stack_a->max = find_max(stack_a);
	stack_a->min = find_min(stack_a);
	stack_a->size = ft_lstsize(stack_a->top);
	sort_args(stack_a, stack_b);
	print_args(stack_a, stack_b);
	clean_all(stack_a, stack_b);
	return (0);
}
