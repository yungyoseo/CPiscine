/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:38:07 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/05 22:45:37 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char n1, char n2, char n3)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	if (n1 == '7' && n2 == '8' && n3 == '9')
		return ;
	else
		write(1, ", ", 2);
}

void	recursive_comb(char n1, char n2, char n3)
{
	if (n1 > '7')
		return ;
	print(n1, n2, n3);
	if (n3 < '9')
		recursive_comb(n1, n2, n3 + 1);
	else if (n2 < '8')
		recursive_comb(n1, n2 + 1, n2 + 2);
	else
		recursive_comb(n1 + 1, n1 + 2, n1 + 3);
}

void	ft_print_comb(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0';
	n2 = '1';
	n3 = '2';
	recursive_comb(n1, n2, n3);
}
