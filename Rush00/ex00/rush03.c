/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:21 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/03 20:57:27 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char left, char mid, char right, int row);

void	rush03(int row, int col)
{
	int	i;

	i = 1;
	ft_putchar('A', 'B', 'C', row);
	if (col == 1)
		return ;
	while (i++ < col - 1)
		ft_putchar('B', ' ', 'B', row);
	ft_putchar('A', 'B', 'C', row);
}
