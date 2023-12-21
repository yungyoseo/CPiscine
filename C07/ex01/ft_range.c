/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:22 by yunseo            #+#    #+#             */
/*   Updated: 2023/12/13 14:30:16 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	idx;
	int	num;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	idx = 0;
	num = min;
	while (num < max)
		arr[idx++] = num++;
	return (arr);
}
