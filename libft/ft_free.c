#include "libft.h"

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}