/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:46:21 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/12 21:20:43 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_upcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 'a' - 'A';
}

void	ft_lowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 'a' - 'A';
}

char	*ft_strcapitalize(char *str)
{
	int		flag;
	char	*start;

	start = str;
	flag = 0;
	while (*str != '\0')
	{
		if (is_alphabet(*str))
		{
			if (flag == 0)
			{
				flag = 1;
				ft_upcase(str);
			}
			else
				ft_lowcase(str);
		}
		else
			flag = 0;
		str++;
	}
	return (start);
}
