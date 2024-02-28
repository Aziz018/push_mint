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

int main(int ac, char **av)
{
    if (ac > 1)
    {
        check_args(ac, av);
        char **strr = malloc(ac * sizeof(char *));
        int i = 0;
        while (i < ac - 1)
        {
            strr[i++] = get_next_line(0);
        }
        strr[i] = NULL;
    free_moves(strr);
    }
}
