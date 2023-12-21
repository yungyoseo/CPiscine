/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:36:42 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/11 21:11:11 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *str, char *to_find)
{
	int	find_idx;

	find_idx = 0;
	while (to_find[find_idx] != '\0')
	{
		if (str[find_idx] != to_find[find_idx])
			return (0);
		find_idx++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_idx;

	if (*to_find == '\0')
		return (str);
	str_idx = 0;
	while (str[str_idx] != '\0')
	{
		if (is_valid(str + str_idx, to_find))
			return (str + str_idx);
		str_idx++;
	}
	return (0);
}
