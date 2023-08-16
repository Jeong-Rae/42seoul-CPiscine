/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:03:02 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/08 11:05:27 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

int	get_op(char *str)
{
	if (!ft_strcmp(str, "+"))
		return (0);
	else if (!ft_strcmp(str, "-"))
		return (1);
	else if (!ft_strcmp(str, "*"))
		return (2);
	else if (!ft_strcmp(str, "/"))
		return (3);
	else if (!ft_strcmp(str, "%"))
		return (4);
	else
		return (-1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++ s1;
		++ s2;
	}
	return (*s1 - *s2);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			result = 10 * result + *str - '0';
		else
			return (sign * result);
		++str;
	}
	return (sign * result);
}
