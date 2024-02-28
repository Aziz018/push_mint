#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*top;
	t_list	*tmp;

	if (stack->top == NULL)
		return (0);
	top = stack->top;
	tmp = top->next;
	while (top)
	{
		tmp = top->next;
		while (tmp)
		{
			if (top->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		top = top->next;
	}
	return (1);
}