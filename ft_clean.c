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
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(char *str, char **arr, char **arrr)
{
	free_arr(arrr);
	free_arr(arr);
	free(str);
}
