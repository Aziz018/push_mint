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

void	rotate_a(t_stack *stack)
{
	t_list	*top;
	t_list	*last;

	top = stack->top;
	last = ft_lstlast(stack->top);
	stack->top = stack->top->next;
	last->next = top;
	top->next = NULL;
	stack->last = top;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	t_list	*top;
	t_list	*last;

	top = stack->top;
	last = ft_lstlast(stack->top);
	stack->top = stack->top->next;
	last->next = top;
	top->next = NULL;
	stack->last = top;
	ft_printf("rb\n");
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
