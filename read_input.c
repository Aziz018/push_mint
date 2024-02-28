#include "push_swap.h"

char **read_input(int ac, char **av)
{
    char **arr = malloc(sizeof(char *) * ac);
    int i = 1;
    int j = 0;
    while (i < ac)
    {
        j = 0;
        arr[i - 1] = malloc(ft_strlen(av[i]) * sizeof(char) + 1);
        while (av[i][j])
        {
            arr[i - 1][j] = av[i][j];
            j++;
        }
        arr[i - 1][j] = '\0';
        i++;
    }
    arr[i - 1] = NULL;
    return(arr);
}
char *arry_to_str(int ac, char **arr)
{
    int i = 0;
    int len = 0;
    while (arr[i] != NULL)
    {
        len += ft_strlen(arr[i]);
        i++;
    }
    char *str = malloc(len * sizeof(char) * ac +  1);
    i = 0;
    int j = 0;
    int k = 0;
    while (arr[i])
    {
        j = 0;
        while (arr[i][j])
        {
            str[k++] = arr[i][j];
            j++;
        }
        str[k++] = ' ';
        i++;
    }
    str[k] = '\0';
    return str;
}
