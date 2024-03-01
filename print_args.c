/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:39:08 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 17:39:46 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	t_list	*tmp;

	tmp = stack->top;
	ft_printf("=======\n");
	while (tmp)
	{
		ft_printf("| %d |\n", tmp->content);
		tmp = tmp->next;
	}
	if (is_empty(stack))
		ft_printf("empty <= ");
	ft_printf("%s\n", str);
	ft_printf("=======\n");
}

void	print_args(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, "stack_a");
	print_stack(stack_b, "stack_b");
}
