/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:00:36 by aelkheta          #+#    #+#             */
/*   Updated: 2024/03/01 12:00:38 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_element(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_a))
		ft_printf("KO");
	else if (is_empty(stack_a) || !is_empty(stack_b))
	{
		clear_stacks(stack_a, stack_b);
		ft_perror("Error");
	}
	else
		ft_printf("Ok");
}

void	which_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (move[0] == 's' && ft_strlen(move) == 3)
		swap(move, stack_a, stack_b);
	else if (move[0] == 'p' && ft_strlen(move) == 3)
		push(move, stack_a, stack_b);
	else if (move[0] == 'r' && ft_strlen(move) == 3)
		rotate(move, stack_a, stack_b);
	else if (move[0] == 'r' && move[1] == 'r' && ft_strlen(move) == 4)
		reverse_rotate(move, stack_a, stack_b);
	else
	{
		free(move);
		clear_stacks(stack_a, stack_b);
		ft_perror("Error");
	}
}

void	check_moves(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (str[0] == '\0')
		{
			free(str);
			return ;
		}
		which_move(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
}

void	main_continue(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	creat_stack(stack_a, ac, av);
	check_moves(stack_a, stack_b);
	check_stack_element(stack_a, stack_b);
	clear_stacks(stack_a, stack_b);
}
