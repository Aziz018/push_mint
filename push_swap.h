/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:23:19 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/03 21:23:22 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_node
// {
//     int data;
//     struct s_stack *next;
// }   t_node;

typedef struct s_stack
{
	int		min;
	int		max;
	int		size;
	int		index;
	int		*array;
	t_list	*top;
	t_list	*last;
}			t_stack;

void		is_duplicated(char **av);
void		check_args(char **av);
int			check_range(t_stack *stack_a, int start, int end);

void		ft_perror(char *str);
void		check_stack_element(t_stack *stack_a, t_stack *stack_b);
void		which_move(char *move, t_stack *stack_a, t_stack *stack_b);
void		check_moves(t_stack *stack_a, t_stack *stack_b);

void		free_it(char **strr);
void		create_list(t_stack *stack, char **strr);
void		creat_stack(t_stack *stack, int ac, char **av);
void		ft_clear_stack(t_stack *stack);

void		clear_stacks(t_stack *stack_a, t_stack *stack_b);
void		free_arr(char **arr);
void		free_all(char *str, char **arr, char **arrr);

int			find_index(t_stack *stack, int num);
void		find_max_push_it(t_stack *stack_a, t_stack *stack_b);
int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			*stack_to_array(t_stack *stack);
int			ft_strstr(char *str1, char *str2);
void		update_range(int *start, int *end, int offset, int size);
void		push_max_element(t_stack *stack_a, t_stack *stack_b);
void		push_and_rotate(t_stack *stack_a, t_stack *stack_b, int middle);

int			is_sorted(t_stack *stack);
void		swap_array_elements(int *array, int j);
int			*sort_array(int *array, int size);

// operations

int			is_empty(t_stack *stack);
int			is_full(t_stack *stack, int ac);
int			pop(t_stack *stack);
void		push_a(t_stack *stack_a, t_stack *stack_b, char *str);
void		push_b(t_stack *stack_a, t_stack *stack_b, char *str);
t_list		*ft_lstbflast(t_list *lst);
void		reverse_rotate_a(t_stack *stack, char *str);
void		reverse_rotate_b(t_stack *stack, char *str);
void		rra_rrb(t_stack *stack_a, t_stack *stack_b, char *str);
void		rotate_a(t_stack *stack, char *str);
void		rotate_b(t_stack *stack, char *str);
void		ra_rb(t_stack *stack_a, t_stack *stack_b, char *str);

// handle the read input

void		is_str_empty(char *str);
char		**read_input(int ac, char **av);
int			give_me_len(char **arr);
char		*arry_to_str(int ac, char **arr);

void		under_10(t_stack *stack_a, t_stack *stack_b);
void		over_10(t_stack *stack_a, t_stack *stack_b);
void		sort_args(t_stack *stack_a, t_stack *stack_b);
void		sort_3(t_stack *stack);
void		sort_5_case(t_stack *stack_a, t_stack *stack_b,
				void (*operation)(t_stack *, char *));
void		sort_5(t_stack *stack_a, t_stack *stack_b);
void		stage_1(t_stack *stack_a, t_stack *stack_b, int offset);
void		stage_2(t_stack *stack_a, t_stack *stack_b);
void		do_it(t_stack *stack_a, t_stack *stack_b);
void		stage_3(t_stack *stack_a, t_stack *stack_b);
void		swap_a(t_stack *stack, char *str);
void		swap_b(t_stack *stack, char *str);
void		sa_sb(t_stack *stack_a, t_stack *stack_b, char *str);

// print argument

void		print_stack(t_stack *stack, char *str);
void		print_args(t_stack *stack_a, t_stack *stack_b);

void		swap(char *move, t_stack *stack_a, t_stack *stack_b);
void		push(char *move, t_stack *stack_a, t_stack *stack_b);
void		rotate(char *move, t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(char *move, t_stack *stack_a, t_stack *stack_b);

// int			*find_lis_sequence(t_stack *stack, int *len);

#endif
