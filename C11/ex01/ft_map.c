#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * length);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tmp[i] = (*f)(tab[i]);
		i++;
	}
	return (tmp);
}
