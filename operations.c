/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:56:05 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 05:56:07 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

int	is_full(t_stack *stack, int ac)
{
	int	size;

	size = ft_lstsize(stack->top);
	if (size == ac - 1)
		return (1);
	return (0);
}

int	pop(t_stack *stack)
{
	int		content;
	t_list	*tmp;

	if (is_empty(stack))
	{
		ft_printf("Stack is empty");
		exit(1);
	}
	tmp = stack->top;
	content = tmp->content;
	stack->top = stack->top->next;
	free(tmp);
	return (content);
}
