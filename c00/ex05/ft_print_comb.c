/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:20:14 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/19 15:00:30 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_print_comb(void)
{
	char	num[3];
	char	comma[2];

	num[0] = '0';
	comma[0] = ',';
	comma[1] = ' ';
	while (num[0] <= '7')
	{
		num[1] = num[0] + 1;
		while (num[1] <= '8')
		{
			num[2] = num[1] + 1;
			while (num[2] <= '9')
			{
				write(1, num, 3);
				if (num[0] != '7')
					write(1, comma, 2);
				++num[2];
			}
			++num[1];
		}
		++num[0];
	}
}
