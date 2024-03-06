/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:07:20 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:48 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(char **av)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_empty_arg(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (is_str_empty(av[i]))
			ft_perror("Error");
		i++;
	}
}

void	free_all_and_exit(char **av, char **arr, char *str)
{
	free_all(str, arr, av);
	ft_perror("Error");
}

void	check_args(char **av, char **arr, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!is_duplicated(av))
		free_all_and_exit(av, arr, str);
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) > 11)
			free_all_and_exit(av, arr, str);
		if ((av[i][0] == '-' || av[i][0] == '+') && ft_isdigit(av[i][1]))
			j++;
		while (av && av[i] && av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				free_all_and_exit(av, arr, str);
			j++;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			free_all_and_exit(av, arr, str);
		i++;
	}
}

int	check_range(t_stack *stack_a, int start, int end)
{
	int		i;
	t_list	*top;

	i = 0;
	top = stack_a->top;
	while (top)
	{
		if (top->content >= stack_a->array[start]
			&& top->content <= stack_a->array[end])
			return (i);
		top = top->next;
		i++;
	}
	return (-1);
}
