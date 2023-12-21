/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:45:54 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/03 21:27:03 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int row, int col);
void	rush01(int row, int col);
void	rush02(int row, int col);
void	rush03(int row, int col);
void	rush04(int row, int col);

void	run_rush(int num, int x, int y)
{
	if (num == 0)
		rush(x, y);
	if (num == 1)
		rush01(x, y);
	if (num == 2)
		rush02(x, y);
	if (num == 3)
		rush03(x, y);
	if (num == 4)
		rush04(x, y);
}

int	error_check(int num, int x, int y)
{
	if (num < 0 || num > 4)
	{
		write(2, "The second argument is must be between 0 and 4\n", 48);
		return (-1);
	}
	if (x == -2 || y == -2)
	{
		write(2, "Error : integer overflow\n", 26);
		return (-1);
	}
	if (x < 1 || y < 1)
	{
		write(2, "Error : The Vaule of argument is must be positive.\n", 52);
		return (-1);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		if (result > (2147483647 - (*str - '0')) / 10)
			return (-2);
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	char	num;
	int		x;
	int		y;

	if (argc != 4)
	{
		write(2, "Error : The number of argument is must be 3\n", 45);
		return (-1);
	}
	num = ft_atoi(argv[1]);
	x = ft_atoi(argv[2]);
	y = ft_atoi(argv[3]);
	if (error_check(num, x, y) != 1)
		return (-1);
	run_rush(num, x, y);
	return (0);
}
