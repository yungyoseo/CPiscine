/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:45:04 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/05 13:10:14 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char left, char mid, char right, int row)
{
	int	i;

	write(1, &left, 1);
	i = 1;
	if (row == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	while (i < row - 1)
	{
		write(1, &mid, 1);
		i++;
	}
	write(1, &right, 1);
	write(1, "\n", 1);
}
