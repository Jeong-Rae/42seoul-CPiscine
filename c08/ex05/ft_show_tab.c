/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:12:22 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/01 08:12:24 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str ++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb < -9)
			ft_putnbr(-1 * (nb / 10));
		ft_putnbr(-1 * (nb % 10));
	}
	else if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_putstr((*par).str);
		write(1, "\n", 1);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_putstr((*par).copy);
		write(1, "\n", 1);
		par ++;
	}
}
