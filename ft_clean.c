/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:38:12 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 17:38:40 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(char *str, char **arr, char **arrr)
{
	if (arrr)
		free_arr(arrr);
	if (arr)
		free_arr(arr);
	if (str)
		free(str);
}

void	ft_perror(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
