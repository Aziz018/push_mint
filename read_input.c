#include "push_swap.h"

char	**read_input(int ac, char **av)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc(sizeof(char *) * ac);
	i = 1;
	j = 0;
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
	return (arr);
}
char	*arry_to_str(int ac, char **arr)
{
	int		i;
	int		len;
	char	*str;
	int		j;
	int		k;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	str = malloc(len * sizeof(char) * ac + 1);
	i = 0;
	j = 0;
	k = 0;
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
	return (str);
}
