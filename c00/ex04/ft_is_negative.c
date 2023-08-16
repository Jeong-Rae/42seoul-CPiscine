/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:03:59 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/19 19:19:01 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	ch_n;
	char	ch_p;

	ch_n = 'N';
	ch_p = 'P';
	if (n < 0)
	{
		write(1, &ch_n, 1);
	}
	else
	{
		write(1, &ch_p, 1);
	}
}
