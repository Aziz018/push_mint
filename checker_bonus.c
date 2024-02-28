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

int main(int ac, char **av)
{
    (void)av;
    if (ac > 1)
    {
        check_args(ac, av);
        char **strr = malloc(ac * sizeof(char *));
        int i = 0;
        while (i < ac - 1)
        {
            strr[i++] = get_next_line(0);
        }
        i = 0;
        while (i < ac - 1)
        {
            ft_printf("strr = %s\n", strr[i]);
            free(strr[i]);
            i++;
        }
        free(strr);
    }
}