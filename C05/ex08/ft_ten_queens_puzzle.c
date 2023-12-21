/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:38:41 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/14 16:02:44 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_result(int *col)
{
	int		i;
	char	num;

	i = 0;
	while (i < 10)
	{
		num = col[i] + '0';
		write(1, &num, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid(int row, int *col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (col[row] == col[i])
			return (0);
		if (row + col[row] == i + col[i])
			return (0);
		if (row - col[row] == i - col[i])
			return (0);
		i++;
	}
	return (1);
}

int	recursive_queen(int row, int *col)
{
	int	n;
	int	cnt;

	if (row == 10)
	{
		print_result(col);
		return (1);
	}
	n = 0;
	cnt = 0;
	while (n < 10)
	{
		col[row] = n;
		if (is_valid(row, col))
			cnt += recursive_queen(row + 1, col);
		n++;
	}
	col[n] = -1;
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	col[12];

	return (recursive_queen(0, col));
}
