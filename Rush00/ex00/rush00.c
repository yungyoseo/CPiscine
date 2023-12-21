/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:59:19 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/03 20:56:03 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char left, char mid, char right, int row);

void	rush(int row, int col)
{
	int	i;

	i = 1;
	ft_putchar('o', '-', 'o', row);
	if (col == 1)
		return ;
	while (i++ < col - 1)
		ft_putchar('|', ' ', '|', row);
	ft_putchar('o', '-', 'o', row);
}
