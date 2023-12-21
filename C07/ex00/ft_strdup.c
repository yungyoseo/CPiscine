/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:13:20 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/16 00:42:07 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen0(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen0(src) + 1));
	while (src[++i] != '\0')
		tmp[i] = src[i];
	tmp[i] = '\0';
	return (tmp);
}
