/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:51:36 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 05:51:39 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_list	*top_a;
	t_list	*top_b;

	if (!is_empty(stack_b))
	{
		top_a = stack_a->top;
		top_b = stack_b->top;
		stack_b->top = stack_b->top->next;
		top_b->next = NULL;
		ft_lstadd_front(&top_a, top_b);
		stack_a->top = top_b;
		stack_a->last = ft_lstlast(stack_a->top);
		if (str == NULL)
			ft_printf("pa\n");
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_list	*top_a;
	t_list	*top_b;

	if (!is_empty(stack_a))
	{
		top_a = stack_a->top;
		top_b = stack_b->top;
		stack_a->top = stack_a->top->next;
		top_a->next = NULL;
		ft_lstadd_front(&top_b, top_a);
		stack_b->top = top_a;
		stack_b->last = ft_lstlast(stack_b->top);
		if (str == NULL)
			ft_printf("pb\n");
	}
}
