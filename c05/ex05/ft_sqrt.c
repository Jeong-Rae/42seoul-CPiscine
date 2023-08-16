/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:33:22 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 22:26:32 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	temp;
	unsigned int	head;
	unsigned int	tail;
	unsigned int	unb;

	head = 1;
	tail = 50000;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	unb = (unsigned int)nb;
	while (head <= tail)
	{
		temp = (head + tail) / 2;
		if (temp * temp == unb)
			return (temp);
		else if (temp * temp > unb)
			tail = temp - 1;
		else if (temp * temp < unb)
			head = temp + 1;
	}
	if (temp * temp == unb)
		return (temp);
	return (0);
}
