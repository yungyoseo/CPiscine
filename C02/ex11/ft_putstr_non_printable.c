/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:56:38 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/13 15:23:04 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_atohex(char c)
{
	char			*hex;
	unsigned char	uc;

	hex = "0123456789abcdef";
	uc = (unsigned char) c;
	write(1, &hex[uc / 16], 1);
	write(1, &hex[uc % 16], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (is_printable(*str))
			ft_putchar(*str);
		else
		{
			write(1, "\\", 1);
			ft_put_atohex(*str);
		}
		str++;
	}
}
