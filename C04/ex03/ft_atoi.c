/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:55:54 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/13 18:11:46 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	negative;
	int	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	negative = 0;
	while ((*str == '-' || *str == '+') && *str != '\0')
	{
		if (*str == '-')
			negative = 1 - negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (negative)
		result = -result;
	return (result);
}
