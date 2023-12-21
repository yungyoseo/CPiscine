/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:50 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/05 22:46:58 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int n)
{
	char	n0;
	char	n1;

	n0 = n / 10 + '0';
	n1 = n % 10 + '0';
	write(1, &n0, 1);
	write(1, &n1, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_print(a);
			write(1, " ", 1);
			ft_print(b);
			if (a == 98 && b == 99)
				break ;
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
