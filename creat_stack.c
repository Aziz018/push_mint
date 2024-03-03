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
	while (strr != NULL && strr[i] != NULL)
	{
		free(strr[i]);
		i++;
	}
	free(strr);
}

int 	create_list(t_stack *stack, char **strr)
{
	int		i;
	// t_list	*head;
	t_list	*node;

	i = 0;
	// head = NULL;
	while (strr[i])
	{
		node = ft_lstnew(ft_atoi(strr[i]));
		if (!node)
			return 0;
		ft_lstadd_back(&stack->top, node);
		i++;
	}
	// stack->top = head;
	stack->last = node;
	return 1;
}

// void	creat_stack(t_stack *stack, char **strr)
// {
// 	int		i;
// 	t_list	*head;
// 	t_list	*node;

// 	i = 0;
// 	head = NULL;
// 	while (strr[i])
// 	{
// 		node = ft_lstnew(ft_atoi(strr[i]));
// 		if (!node)
// 		{
// 			ft_clear_stack(stack);
// 			ft_perror("Error in lstnew");
// 		}
// 		ft_lstadd_back(&stack->top, node);
// 		i++;
// 	}
// 	// stack->top = head;
// 	stack->last = node;
// }

void	creat_stack(t_stack *stack, int ac, char **av)
{
	char	*str;
	char	**array;
	char	**strr;

	array = read_input(ac, av);
	str = arry_to_str(ac, array);
	strr = ft_split(str, ' ');
	if (!create_list(stack, strr))
	{
		ft_clear_stack(stack);
		free_all(str, array, strr);
		ft_perror("fail creat stack");
	}
	free_all(str, array, strr);
}

void	ft_clear_stack(t_stack *stack)
{
	t_list	*top;
	t_list	*tmp;

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
