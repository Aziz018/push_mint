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
			if (av[i][0] == '-' && ft_isdigit(av[i][1]))
				j++;
			else if (!ft_isdigit(av[i][j]))
				ft_perror("Error");
			j++;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			ft_perror("Error");
		i++;
	}
}

int	check_range(t_stack *stack_a, int start, int end)
{
	t_list	*top;

	top = stack_a->top;
	while (top)
	{
		if (top->content >= stack_a->array[start]
			&& top->content <= stack_a->array[end])
			return (1);
		top = top->next;
	}
	return (0);
}
