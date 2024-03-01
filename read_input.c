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

void	is_str_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		ft_perror("Error");
}

char	**read_input(int ac, char **av)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc(sizeof(char *) * ac);
	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		is_str_empty(av[i]);
		if (av[i][0] == '\0')
			ft_perror("Error");
		arr[i - 1] = malloc(ft_strlen(av[i]) * sizeof(char) + 1);
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
char	*arry_to_str(int ac, char **arr)
{
	int		i;
	int		len;
	char	*str;
	int		j;
	int		k;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	str = malloc(len * sizeof(char) * ac + 1);
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
	return (str);
}
