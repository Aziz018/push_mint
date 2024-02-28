/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:23:14 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/03 21:23:16 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ft_printf("\033[1;33m");
	// ft_printf("                 _                                 \n");
	// ft_printf(" _ __  _   _ ___| |__      _____      ____ _ _ __  \n");
	// ft_printf("| '_ \\| | | / __| '_ \\    / __\\ \\ /\\ / / _` | '_ \\ \n");
	// ft_printf("| |_) | |_| \\__ \\ | | |   \\__ \\\\ V  V / (_| | |_) |\n");
	// ft_printf("| .__/ \\__,_|___/_| |_|___|___/ \\_/\\_/ \\__,_| .__/ \n");
	// ft_printf("|_|                  |_____|                |_|    \n\n\n");
	// ft_printf("\033[0m");
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	check_check(ac, av);
	creat_stack(stack_a, ac, av);
	stack_a->max = find_max(stack_a);
	stack_a->min = find_min(stack_a);
	stack_a->size = ft_lstsize(stack_a->top);
	sort_args(stack_a, stack_b);
	if (is_sorted(stack_a))
	{
		ft_printf("\x1b[1;32m");
	// ft_printf("\n     _                  \n");
	// ft_printf("  __| | ___  _ __   ___ \n");
	// ft_printf(" / _` |/ _ \\| '_ \\ / _ \\\n");
	// ft_printf("| (_| | (_) | | | |  __/\n");
	// ft_printf(" \\__,_|\\___/|_| |_|\\___|\n\n");
		ft_printf("\ndone\n");
		ft_printf("\x1b[0m");
	}
	else
		ft_printf("not sorted\n");
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	return (0);
}
