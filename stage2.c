/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:36:51 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/02 10:36:53 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage_2(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size -= 1;
	push_max_element(stack_a, stack_b);
	while (stack_b->top && stack_a->size >= 0)
	{
		if (stack_b->top->content == stack_a->array[stack_a->size])
		{
			push_a(stack_a, stack_b, NULL);
			stack_a->size -= 1;
		}
		else
			find_max_push_it(stack_a, stack_b);
	}
	free(stack_a->array);
}

void	do_it(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top->content == stack_a->array[stack_a->size])
	{
		push_a(stack_a, stack_b, NULL);
		stack_a->size -= 1;
	}
	else
	{
		if (stack_a->last->content == stack_b->max)
		{
			push_a(stack_a, stack_b, NULL);
			rotate_a(stack_a, NULL);
		}
		else if (stack_a->last->content == stack_a->array[stack_a->size])
		{
			reverse_rotate_a(stack_a, NULL);
			stack_a->size -= 1;
		}
		else
			find_max_push_it(stack_a, stack_b);
	}
}

void	stage_3(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size -= 1;
	stack_b->max = stack_a->array[stack_a->size];
	push_max_element(stack_a, stack_b);
	while (stack_b->top)
	{
		do_it(stack_a, stack_b);
	}
	if (stack_a->last->content < stack_a->top->content)
		reverse_rotate_a(stack_a, NULL);
	free(stack_a->array);
}
