/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:31:03 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/02 10:31:05 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		i;
	t_list	*top;

	i = 0;
	stack->array = malloc(sizeof(int) * (stack->size));
	top = stack->top;
	while (top)
	{
		stack->array[i] = top->content;
		top = top->next;
		i++;
	}
	return (stack->array);
}

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

void	update_range(int *start, int *end, int offset, int size)
{
	*start -= offset;
	*end += offset;
	if (*start < 0)
		*start = 0;
	if (*end >= size)
		*end = size - 1;
}

void	push_max_element(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->index = find_index(stack_b, stack_b->max);
	if (stack_a->index < stack_a->size / 2)
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			rotate_b(stack_b, NULL);
	}
	else
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			reverse_rotate_b(stack_b, NULL);
	}
	push_a(stack_a, stack_b, NULL);
	stack_a->size -= 1;
}

void	push_and_rotate(t_stack *stack_a, t_stack *stack_b, int middle)
{
	push_b(stack_a, stack_b, NULL);
	if (stack_b->top->next && stack_b->top->content < stack_a->array[middle])
		rotate_b(stack_b, NULL);
}
