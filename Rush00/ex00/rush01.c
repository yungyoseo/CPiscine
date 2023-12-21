/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bygim <bygim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:28:25 by bygim             #+#    #+#             */
/*   Updated: 2023/12/03 20:55:43 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char left, char mid, char right, int row);

void	rush01(int row, int col)
{
	int	i;

	i = 1;
	ft_putchar('/', '*', '\\', row);
	if (col == 1)
		return ;
	while (i++ < col - 1)
		ft_putchar('*', ' ', '*', row);
	ft_putchar('\\', '*', '/', row);
}
