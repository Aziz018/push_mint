/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:27 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 17:40:29 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_str_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	allocate_arr(char **av, char **arr, int i)
{
	arr[i - 1] = malloc(ft_strlen(av[i]) * sizeof(char) + 1);
	if (arr[i - 1] == NULL)
	{
		free_it(arr);
		ft_perror("Allocation error");
	}
}

char	**read_input(int ac, char **av)
{
	char	**arr;
	int		i;
	int		j;

	check_empty_arg(ac, av);
	arr = malloc(sizeof(char *) * ac);
	if (!arr)
		exit(1);
	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		allocate_arr(av, arr, i);
		while (av[i][j])
		{
			arr[i - 1][j] = av[i][j];
			j++;
		}
		arr[i - 1][j] = '\0';
		i++;
	}
	arr[i - 1] = NULL;
	return (arr);
}

void	copy_args(char **arr, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			str[k++] = arr[i][j];
			j++;
		}
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
}

char	*arry_to_str(int ac, char **arr)
{
	int		len;
	char	*str;

	len = give_me_len(arr);
	str = malloc(len * sizeof(char) * ac + 1);
	if (!str)
	{
		free_it(arr);
		ft_perror("Allocation error");
	}
	copy_args(arr, str);
	return (str);
}
