/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:27:44 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/17 21:46:09 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	is_valid_base(char *base);

int	nbr_len_base(int nbr, char *base)
{
	int	cnt;
	int	base_len;

	cnt = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
		cnt++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		cnt++;
	}
	return (cnt);
}

char	*ft_itos_base(int nbr, char *base, int len)
{
	int		base_len;
	int		i;
	int		num;
	char	*result;

	base_len = ft_strlen(base);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr < 0)
		result[0] = '-';
	if (nbr == 0)
		result[0] = base[0];
	i = len - 1;
	if (result == 0)
		return (0);
	while (nbr != 0)
	{
		num = nbr % base_len;
		if (num < 0)
			num = -num;
		result[i] = base[num];
		nbr /= base_len;
		i--;
	}
	result[len] = '\0';
	return (result);
}

int	find_base_num(char *str, char *base)
{
	int	i;
	int	result;
	int	base_len;
	int	base_idx;

	i = 0;
	result = 0;
	base_len = ft_strlen(base);
	while (str[i] != '\0')
	{
		base_idx = 0;
		while (base[base_idx] != '\0')
		{
			if (str[i] == base[base_idx])
				break ;
			base_idx++;
		}	
		if (base[base_idx] == '\0')
			break ;
		result = result * base_len + base_idx;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = find_base_num(str, base);
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*tmp;
	int		num;
	int		len;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	len = nbr_len_base(num, base_to);
	tmp = ft_itos_base(num, base_to, len);
	return (tmp);
}
