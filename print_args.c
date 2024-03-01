#include "push_swap.h"

void	print_args(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack_a->top;
	// (void)stack_b;
	tmp2 = stack_b->top;
	ft_printf("=======\n");
	while (tmp1)
	{
		ft_printf("| %d |\n", tmp1->content);
		tmp1 = tmp1->next;
	}
	if (is_empty(stack_a))
		ft_printf("empty <= ");
	ft_printf("stack a\n");
	ft_printf("=======\n");
	ft_printf("=======\n");
	while (tmp2)
	{
		if (!is_empty(stack_b))
		{
			ft_printf("| %d |\n", tmp2->content);
			tmp2 = tmp2->next;
		}
	}
	if (is_empty(stack_b))
		ft_printf("empty <= ");
	ft_printf("stack b\n");
	ft_printf("=======\n");
}