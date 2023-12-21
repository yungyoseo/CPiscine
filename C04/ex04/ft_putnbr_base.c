/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:24:02 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/21 18:05:15 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		i;
	int		num;
	char	result[33];

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	i = 0;
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr == 0)
		write(1, &base[0], 1);
	while (nbr != 0)
	{
		num = nbr % base_len;
		if (num < 0)
			num = -num;
		result[i++] = base[num];
		nbr /= base_len;
	}
	while (i > 0)
		write(1, &result[--i], 1);
}
