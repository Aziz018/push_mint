/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:07:20 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 06:07:22 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_args(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack_a->top;
	// (void)stack_b;
	tmp2 = stack_b->top;
	// ft_printf("=======\n");
	while (tmp1)
	{
		ft_printf("| %d | ", tmp1->content);
		tmp1 = tmp1->next;
	}
	if (is_empty(stack_a))
		ft_printf("empty <= ");
	ft_printf("stack a\n");
	// ft_printf("=======\n");
	// ft_printf("=======\n");
	while (tmp2)
	{
		if (!is_empty(stack_b))
		{
			ft_printf("| %d | ", tmp2->content);
			tmp2 = tmp2->next;
		}
	}
	if (is_empty(stack_b))
		ft_printf("empty <= ");
	ft_printf("stack b\n");
	// ft_printf("=======\n");
}

void	check_check(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
	{
		ft_printf("error");
		exit(1);
	}
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			j = i + 1;
			if (av[i][0] == '\0')
			{
				ft_printf("Error");
				exit(1);
			}
			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			{
				ft_printf("Error");
				exit(1);
			}
			while (j < ac)
			{
				if (ft_atoi(av[i]) == ft_atoi(av[j]))
				{
					ft_printf("Error");
					exit(1);
				}
				j++;
			}
			i++;
		}
	}
}

int	find_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->top;
	max = 0;
	if (!is_empty(stack))
	{
		max = tmp->content;
		while (tmp && tmp->next)
		{
			if (max < tmp->next->content)
				max = tmp->next->content;
			tmp = tmp->next;
		}
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;

	min = 0;
	tmp = stack->top;
	if (!is_empty(stack))
	{
		min = tmp->content;
		while (tmp && tmp->next)
		{
			if (min > tmp->next->content)
				min = tmp->next->content;
			tmp = tmp->next;
		}
	}
	return (min);
}
