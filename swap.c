/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:50:37 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 05:50:38 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		first = stack->top;
		second = stack->top->next;
		first->next = second->next;
		second->next = stack->top;
		stack->top = second;
		stack->last = ft_lstlast(stack->top);
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack *stack)
{
	t_list	*ptr;
	t_list	*first;
	t_list	*second;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		first = stack->top;
		second = stack->top->next;
		ptr = first;
		first->next = second->next;
		second->next = ptr;
		stack->top = second;
		stack->last = ft_lstlast(stack->top);
		ft_printf("sb\n");
	}
}

void	sa_sb(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
