/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:07:04 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/07 17:41:35 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_last(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] != '9' - (size - i - 1))
			return (0);
		i++;
	}
	return (1);
}

void	ft_comb(char *str, int size, int n)
{
	if (n == size)
	{
		write(1, str, size);
		if (!is_last(str, size))
			write(1, ", ", 2);
		return ;
	}
	str[n + 1] = str[n] + 1;
	while (str[n] - '0' <= 9 - (size - n - 1))
	{
		str[n + 1] = str[n] + 1;
		ft_comb(str, size, n + 1);
		str[n]++;
	}
}

void	ft_print_combn(int n)
{
	char	str[11];

	if (n < 1 || n > 9)
		return ;
	str[0] = '0';
	ft_comb(str, n, 0);
}
