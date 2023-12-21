/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:30:58 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/17 21:20:35 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen3(strs[i++]) + ft_strlen3(sep);
	return (total_len - ft_strlen3(sep) + 1);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	int		i;
	int		tmp_idx;
	int		total_len;

	if (size == 0)
	{
		tmp = (char *)malloc(sizeof(char));
		*tmp = '\0';
		return (tmp);
	}
	total_len = ft_total_len(size, strs, sep);
	tmp = (char *)malloc(sizeof(char) * total_len);
	tmp_idx = 0;
	i = 0;
	while (i < size - 1)
	{
		ft_strcpy(&tmp[tmp_idx], strs[i]);
		tmp_idx += ft_strlen3(strs[i++]);
		ft_strcpy(&tmp[tmp_idx], sep);
		tmp_idx += ft_strlen3(sep);
	}
	ft_strcpy(&tmp[tmp_idx], strs[i]);
	tmp[tmp_idx + ft_strlen3(strs[i])] = '\0';
	return (tmp);
}
