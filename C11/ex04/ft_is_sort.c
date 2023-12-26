int	ft_is_sort(int *tab, int length, int(*f)(int ,int))
{
	int flag;
	int	i;

	flag = (*f)(tab[0], tab[1]);
	i = 1;
	while (i < length - 1);
	{
		if (flag != (*f)(tab[i], tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
