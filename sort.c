/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:04:14 by aelkheta          #+#    #+#             */
/*   Updated: 2024/02/12 06:04:16 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_index(t_stack *stack, int num)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp && tmp->content != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (-1);
	stack->index = i;
	return (i);
}

void	sort_3(t_stack *stack)
{
	stack->max = find_max(stack);
	while (stack->last->content != stack->max)
		rotate_a(stack);
	if (stack->top->content > stack->top->next->content)
		swap_a(stack);
}

void	sort_5_case(t_stack *stack_a, t_stack *stack_b,
		void (*operation)(t_stack *))
{
	int		i;
	t_list	*top;

	i = 2;
	while (i)
	{
		stack_a->min = find_min(stack_a);
		top = stack_a->top;
		while (top->content != stack_a->min)
		{
			operation(stack_a);
			top = stack_a->top;
		}
		push_b(stack_a, stack_b);
		i--;
	}
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->min = find_min(stack_a);
	find_index(stack_a, stack_a->min);
	if (stack_a->index >= stack_a->size / 2)
		sort_5_case(stack_a, stack_b, &reverse_rotate_a);
	else
		sort_5_case(stack_a, stack_b, &rotate_a);
}

int	*stack_to_array(t_stack *stack)
{
	int		i;
	t_list	*top;

	i = 0;
	stack->array = malloc(sizeof(int) * (stack->size));
	top = stack->top;
	while (top)
	{
		stack->array[i] = top->content;
		top = top->next;
		i++;
	}
	return (stack->array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	swap;
	int	flag;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		flag = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return (array);
		i++;
	}
	return (array);
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

void	update_range(int *start, int *end, int offset, int size)
{
	*start -= offset;
	*end += offset;
	if (*start < 0)
		*start = 0;
	if (*end >= size)
		*end = size - 1;
}

void	push_max_element(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->top->content != stack_a->array[stack_a->size])
	{
		rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
	stack_a->size -= 1;
}

void	find_max_push_it(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->index = find_index(stack_b, stack_a->array[stack_a->size]);
	if (stack_b->index > (stack_a->size / 2))
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			reverse_rotate_b(stack_b);
	}
	else
	{
		while (stack_b->top->content != stack_a->array[stack_a->size])
			rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
	stack_a->size -= 1;
}

void	stage_1(t_stack *stack_a, t_stack *stack_b, int offset)
{
	int	size;
	int	middle;
	int	end;
	int	start;

	size = stack_a->size;
	middle = size / 2 - 1;
	end = middle + offset;
	start = middle - offset;
	stack_to_array(stack_a);
	stack_a->array = sort_array(stack_a->array, size);
	while (stack_a->top)
	{
		if (stack_a->top->content >= stack_a->array[start]
			&& stack_a->top->content <= stack_a->array[end])
		{
			push_b(stack_a, stack_b);
			if (stack_b->top->next
				&& stack_b->top->content < stack_a->array[middle])
				rotate_b(stack_b);
		}
		else
		{
			if (check_range(stack_a, start, end))
				rotate_a(stack_a);
			else
				update_range(&start, &end, offset, size);
		}
	}
}

void	stage_2(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size -= 1;
	push_max_element(stack_a, stack_b);
	while (stack_b->top && stack_a->size >= 0)
	{
		if (stack_b->top->content == stack_a->array[stack_a->size])
		{
			push_a(stack_a, stack_b);
			stack_a->size -= 1;
		}
		else
			find_max_push_it(stack_a, stack_b);
	}
	free(stack_a->array);
}
void	stage_3(t_stack *stack_a, t_stack *stack_b)
{
	// int flag = 1;
	stack_a->size -= 1;
	stack_b->max = stack_a->array[stack_a->size];
	push_max_element(stack_a, stack_b);
	while (stack_b->top)
	{
		if (stack_b->top->content == stack_a->array[stack_a->size])
		{
			push_a(stack_a, stack_b);
			stack_a->size -= 1;
		}
		else
		{
			if (stack_a->last->content == stack_b->max)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
			}
			else if (stack_a->last->content == stack_a->array[stack_a->size])
			{
				reverse_rotate_a(stack_a);
				stack_a->size -= 1;
			}
			else
				find_max_push_it(stack_a, stack_b);
		}
	}
	if (stack_a->last->content < stack_a->top->content)
		reverse_rotate_a(stack_a);
	free(stack_a->array);
}

void	sort_args(t_stack *stack_a, t_stack *stack_b)
{
	int	offset;

	if (stack_a->top == NULL)
		exit(0);
	else if (is_sorted(stack_a))
		exit(0);
	else if (stack_a->size <= 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size <= 10)
	{
		offset = 2;
		stage_1(stack_a, stack_b, offset);
		stage_2(stack_a, stack_b);
		print_args(stack_a, stack_b);

	}
	else if (stack_a->size <= 100)
	{
		offset = stack_a->size / 10;
		stage_1(stack_a, stack_b, offset);
		stage_2(stack_a, stack_b);
		print_args(stack_a, stack_b);

	}
	else
	{
		offset = stack_a->size / 18;
		stage_1(stack_a, stack_b, offset);
		stage_3(stack_a, stack_b);
		print_args(stack_a, stack_b);
	}
}
