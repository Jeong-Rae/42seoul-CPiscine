/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:40:06 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/19 16:01:05 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_print_to_99(char ten, char one)
{
	char	num[2];

	num[0] = ten;
	num[1] = one;
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			if (ten == num[0] && one == num[1])
			{
				++num[1];
				continue ;
			}
			if (ten == '9' && one == '8' && num[0] == '9' && num[1] == '9')
				return ;
			write(1, &ten, 1);
			write(1, &one, 1);
			write(1, " ", 1);
			write(1, num, 2);
			write(1, ", ", 2);
			++num[1];
		}
		++num[0];
		num[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	num[3];

	num[0] = '0';
	num[1] = '0';
	num[2] = ' ';
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			ft_print_to_99(num[0], num[1]);
			++num[1];
		}
		++num[0];
		num[1] = '0';
	}
	write(1, "98 99", 5);
}
