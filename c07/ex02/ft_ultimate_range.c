/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:02:30 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 16:04:50 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*numbers;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	numbers = (int *)malloc(size * sizeof(int));
	if (!numbers)
		return (-1);
	*range = numbers;
	i = 0;
	while (i < size)
	{
		numbers[i] = min + i;
		i++;
	}
	return (size);
}
