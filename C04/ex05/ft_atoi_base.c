/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:54:18 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/21 20:54:03 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (base[i] == '-' || base[i] == '+')
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

	if (!is_valid_base(base))
		return (0);
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
