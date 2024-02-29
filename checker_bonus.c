#include "push_swap.h"

void checker()
{

}

void check_args(int ac, char **av)
{
    int i = 1;
    int j = 0;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '\0')
        {
            ft_printf("Error");
            exit(1);
        }
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
            {
                ft_printf("Error");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void free_moves(char **strr)
{
    int i;
    
    i = 0;
    while (strr[i])
    {
        free(strr[i]);
        i++;
    }
    free(strr);
}

int ft_strstr(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\n' || str2[i])
    {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    if (str1[i] == '\n' && str2[i] == '\0')
        return 1;
    return 0;
}

void swap(char *move, t_stack *stack_a, t_stack *stack_b)
{
    if (ft_strstr(move, "sa"))
        swap_a(stack_a);
    else if (ft_strstr(move, "sb"))
        swap_b(stack_b);
    else if (ft_strstr(move, "ss"))
    {
        swap_a(stack_a);
        swap_b(stack_b);
    }
}
void push(char *move, t_stack *stack_a, t_stack *stack_b)
{
    if (ft_strstr(move, "pa"))
        push_a(stack_a, stack_b);
    else if (ft_strstr(move, "pb"))
        push_b(stack_a, stack_b);
}

void rotate(char *move, t_stack *stack_a, t_stack *stack_b)
{
    if (ft_strstr(move, "ra"))
        rotate_a(stack_a);
    else if (ft_strstr(move, "rb"))
        rotate_b(stack_b);
    else if (ft_strstr(move, "rr"))
    {
        rotate_a(stack_a);
        rotate_b(stack_b);
    }
}

void reverse_rotate(char *move, t_stack *stack_a, t_stack *stack_b)
{
    if (ft_strstr(move, "rra"))
        reverse_rotate_a(stack_a);
    else if (ft_strstr(move, "rrb"))
        reverse_rotate_b(stack_b);
    else if (ft_strstr(move, "rrr"))
    {
        reverse_rotate_a(stack_a);
        reverse_rotate_b(stack_b);
    }
}

void which_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
    if (move[0] == 's')
        swap(move, stack_a, stack_b);
    else if (move[0] == 'p')
        push(move, stack_a, stack_b);
    else if (move[0] == 'r' && ft_strlen(move) == 3)
        rotate(move, stack_a, stack_b);
    else if (move[0] == 'r' && move[1] == 'r')
        rotate(move, stack_a, stack_b);
    else
    {
        ft_printf("Error");
        exit(1);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    check_args(ac, av);
    t_stack *stack_a;
    t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
    stack_a->top = NULL;
    stack_b->top = NULL;
    creat_stack(stack_a, ac, av);
    char **strr = malloc(ac * sizeof(char *));
    int i = 0;
    strr[i] = get_next_line(0);
    while (strr[i] && strr[i][0] != '\n')
    {
        which_move(strr[i], stack_a, stack_b);
        i++;
        strr[i] = get_next_line(0);
    }
    strr[++i] = NULL;
    if (is_empty(stack_a) || !is_empty(stack_b))
    {
        ft_printf("Error");
        ft_clear_stack(stack_a);
        ft_clear_stack(stack_b);
        free_moves(strr);
        print_args(stack_a, stack_b);
        exit(1);
    }
    if (!is_sorted(stack_a))
        ft_printf("KO\n");
    else
        ft_printf("Ok\n");
    print_args(stack_a, stack_b);
    ft_clear_stack(stack_a);
    ft_clear_stack(stack_b);
    free_moves(strr);
}
