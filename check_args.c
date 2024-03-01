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

void	is_duplicated(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_perror("Error");
			j++;
		}
		i++;
	}
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_duplicated(av);
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) > 11)
			ft_perror("Error");
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_perror("Error");
			j++;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			ft_perror("Error");
		i++;
	}
}

// void	check_check(int ac, char **av)
// {
// 	int	i;
// 	int	j;

// 	if (ac < 2)
// 	{
// 		ft_printf("error");
// 		exit(1);
// 	}
// 	if (ac > 1)
// 	{
// 		i = 1;
// 		while (i < ac)
// 		{
// 			j = i + 1;
// 			if (av[i][0] == '\0')
// 			{
// 				ft_printf("Error");
// 				exit(1);
// 			}
// 			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
// 			{
// 				ft_printf("Error");
// 				exit(1);
// 			}
// 			while (j < ac)
// 			{
// 				if (ft_atoi(av[i]) == ft_atoi(av[j]))
// 				{
// 					ft_printf("Error");
// 					exit(1);
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// }

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
