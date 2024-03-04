/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:36:43 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/02 10:36:45 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	stack->max = find_max(stack);
	while (stack->last->content != stack->max)
		rotate_a(stack, NULL);
	if (stack->top->content > stack->top->next->content)
		swap_a(stack, NULL);
}

void	sort_5_case(t_stack *stack_a, t_stack *stack_b,
		void (*operation)(t_stack *, char *))
{
	int		i;
	t_list	*top;

	i = 2;
	while (i)
	{
		stack_a->min = find_min(stack_a);
		top = stack_a->top;
		while (top->content != stack_a->min)
		{
			operation(stack_a, NULL);
			top = stack_a->top;
		}
		push_b(stack_a, stack_b, NULL);
		i--;
	}
	sort_3(stack_a);
	push_a(stack_a, stack_b, NULL);
	push_a(stack_a, stack_b, NULL);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->min = find_min(stack_a);
	find_index(stack_a, stack_a->min);
	if (stack_a->index >= stack_a->size / 2)
		sort_5_case(stack_a, stack_b, &reverse_rotate_a);
	else
		sort_5_case(stack_a, stack_b, &rotate_a);
}

void	stage_1(t_stack *stack_a, t_stack *stack_b, int offset)
{
	int	size;
	int	middle;
	int	end;
	int	start;

	size = stack_a->size;
	middle = size / 2 - 1;
	end = middle + offset;
	start = middle - offset;
	stack_to_array(stack_a);
	stack_a->array = sort_array(stack_a->array, size);
	while (stack_a->top)
	{
		if (stack_a->top->content >= stack_a->array[start]
			&& stack_a->top->content <= stack_a->array[end])
			push_and_rotate(stack_a, stack_b, middle);
		else
		{
			if (check_range(stack_a, start, end) != -1)
				rotate_a(stack_a, NULL);
			else
				update_range(&start, &end, offset, size);
		}
	}
}
