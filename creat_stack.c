/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:02:40 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/11 19:02:42 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_it(char **strr)
{
	int	i;

	i = 0;
	while (strr[i])
	{
		free(strr[i]);
		i++;
	}
	free(strr);
}

void	creat_stack(t_stack *stack, int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*node;
	char	**array;
	char	*str;
	char	**strr;

	i = 0;
	head = NULL;
	array = read_input(ac, av);
	str = arry_to_str(ac, array);
	strr = ft_split(str, ' ');
	while (strr[i])
	{
		node = ft_lstnew(ft_atoi(strr[i]));
		ft_lstadd_back(&head, node);
		i++;
	}
	free_it(array);
	free_it(strr);
	free(str);
	stack->top = head;
	stack->last = node;
}

void	ft_clear_stack(t_stack *stack)
{
	t_list *top;
	t_list *tmp;

	top = stack->top;
	top = stack->top;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(stack);
}