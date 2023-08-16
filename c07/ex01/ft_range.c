/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:03:03 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 18:04:08 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>
#include<stdio.h>
int	*ft_range(int min, int max)
{
	int	size;
	int	idx;
	int	*range;

	size = max - min;
	if (size <= 0)
		return (NULL);
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (0);
	idx = 0;
	while (idx < size)
	{
		range[idx] = min + idx;
		++ idx;
	}
	printf("%d",size);
	/* for (int i = 0; i < size; i++)
	{
		printf("%d ",range[i]);
	}
 */
	return (range);
}

int main()
{
	ft_range(2147483647,-111111111);
}
