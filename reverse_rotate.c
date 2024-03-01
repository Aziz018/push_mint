/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:55:56 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 05:55:58 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstbflast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	reverse_rotate_a(t_stack *stack, char *str)
{
	t_list	*top;
	t_list	*last;
	t_list	*befor_last;

	if (stack->top && stack->top->next)
	{
		top = stack->top;
		last = stack->last;
		befor_last = ft_lstbflast(stack->top);
		befor_last->next = NULL;
		ft_lstadd_front(&top, last);
		stack->top = last;
		stack->last = befor_last;
		if (str == NULL)
			ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_stack *stack, char *str)
{
	t_list	*top;
	t_list	*last;
	t_list	*befor_last;

	if (stack->top && stack->top->next)
	{
		top = stack->top;
		last = ft_lstlast(stack->top);
		befor_last = ft_lstbflast(stack->top);
		befor_last->next = NULL;
		ft_lstadd_front(&top, last);
		stack->top = last;
		stack->last = befor_last;
		if (str == NULL)
			ft_printf("rrb\n");
	}
}

void	rra_rrb(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (stack_a->top && stack_a->top->next && stack_b->top
		&& stack_b->top->next)
	{
		reverse_rotate_a(stack_a, str);
		reverse_rotate_b(stack_b, str);
		if (str == NULL)
			ft_printf("rrr\n");
	}
}
