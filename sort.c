/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:04:14 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 06:04:16 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under_10(t_stack *stack_a, t_stack *stack_b)
{
	int	offset;

	if (is_sorted(stack_a))
		exit(0);
	else if (stack_a->size <= 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size <= 10)
	{
		offset = 2;
		stage_1(stack_a, stack_b, offset);
		stage_2(stack_a, stack_b);
		print_args(stack_a, stack_b);
	}
}

void	over_10(t_stack *stack_a, t_stack *stack_b)
{
	int	offset;

	if (stack_a->size <= 100)
	{
		offset = stack_a->size / 10;
		stage_1(stack_a, stack_b, offset);
		stage_2(stack_a, stack_b);
	}
	else
	{
		offset = stack_a->size / 18;
		stage_1(stack_a, stack_b, offset);
		stage_3(stack_a, stack_b);
	}
}

void	sort_args(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == NULL)
		exit(0);
	else if (stack_a->size <= 10)
		under_10(stack_a, stack_b);
	else if (stack_a->size > 10)
		over_10(stack_a, stack_b);
}
