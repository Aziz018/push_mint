/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:26:39 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/02 10:26:41 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int num)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp && tmp->content != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (-1);
	stack->index = i;
	return (i);
}

void	find_max_push_it(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->index = find_index(stack_b, stack_a->array[stack_a->size]);
	if (stack_b->index >= (stack_a->size / 2))
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			reverse_rotate_b(stack_b, NULL);
	}
	else
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			rotate_b(stack_b, NULL);
	}
	push_a(stack_a, stack_b, NULL);
	stack_a->size -= 1;
}

int	find_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->top;
	max = 0;
	if (!is_empty(stack))
	{
		max = tmp->content;
		while (tmp && tmp->next)
		{
			if (max < tmp->next->content)
				max = tmp->next->content;
			tmp = tmp->next;
		}
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;

	min = 0;
	tmp = stack->top;
	if (!is_empty(stack))
	{
		min = tmp->content;
		while (tmp && tmp->next)
		{
			if (min > tmp->next->content)
				min = tmp->next->content;
			tmp = tmp->next;
		}
	}
	return (min);
}
