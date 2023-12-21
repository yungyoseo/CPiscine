/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:52:24 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/17 22:24:51 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 1;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], sep))
		{
			while (!is_sep(str[i], sep))
				i++;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

char	*copy_str(char *str, char *sep)
{
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	while (str[len] != '\0' && !is_sep(str[len], sep))
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**tmp;
	int		i;
	int		tmp_idx;

	i = 0;
	tmp_idx = 0;
	tmp = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!tmp)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str[i], charset))
			i++;
		if (str[i] != '\0' && !is_sep(str[i], charset))
			tmp[tmp_idx] = copy_str(&str[i], charset);
		while (str[i] != '\0' && !is_sep(str[i], charset))
			i++;
		tmp_idx++;
	}
	tmp[tmp_idx] = 0;
	return (tmp);
}
