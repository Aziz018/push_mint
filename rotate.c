/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:55:49 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 05:55:52 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack, char *str)
{
	t_list	*top;
	t_list	*last;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		top = stack->top;
		last = ft_lstlast(stack->top);
		stack->top = stack->top->next;
		last->next = top;
		top->next = NULL;
		stack->last = top;
		if (str == NULL)
			ft_printf("ra\n");
	}
}

void	rotate_b(t_stack *stack, char *str)
{
	t_list	*top;
	t_list	*last;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		top = stack->top;
		last = ft_lstlast(stack->top);
		stack->top = stack->top->next;
		last->next = top;
		top->next = NULL;
		stack->last = top;
		if (str == NULL)
			ft_printf("rb\n");
	}
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (stack_a->top != NULL && stack_a->top->next != NULL
		&& stack_b->top != NULL && stack_b->top->next != NULL)
	{
		rotate_a(stack_a, str);
		rotate_b(stack_b, str);
		if (str == NULL)
			ft_printf("rr\n");
	}
}
