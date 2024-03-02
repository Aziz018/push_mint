/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:01:36 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 12:01:38 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*top;
	t_list	*tmp;

	if (stack->top == NULL)
		return (0);
	top = stack->top;
	tmp = top->next;
	while (top)
	{
		tmp = top->next;
		while (tmp)
		{
			if (top->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		top = top->next;
	}
	return (1);
}

void	swap_array_elements(int *array, int j)
{
	int	swap;

	swap = array[j];
	array[j] = array[j + 1];
	array[j + 1] = swap;
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		flag = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				swap_array_elements(array, j);
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return (array);
		i++;
	}
	return (array);
}
