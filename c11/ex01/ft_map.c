/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:19:36 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 19:23:51 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (0);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i ++;
	}
	return (result);
}
