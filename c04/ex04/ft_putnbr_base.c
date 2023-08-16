/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:35 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 22:28:53 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_invalid(char *base, int *len)
{
	int	idx;
	int	flag;
	int	j;

	idx = 0;
	flag = 0;
	while (base[idx])
	{
		if (base[idx] == '+' || base[idx] == '-')
			flag = 1;
		j = idx + 1;
		while (base[j])
		{
			if (base[idx] == base[j])
				flag = 1;
			++j;
		}
		++idx;
	}
	*len = idx;
	if (idx < 2 || flag)
		return (1);
	return (0);
}

void	ft_rec_putnbr_negative(unsigned int nb, unsigned int radix, char *base)
{
	if (nb < radix)
	{
		write(1, &base[nb], 1);
	}
	else
	{
		ft_rec_putnbr_negative(nb / radix, radix, base);
		ft_rec_putnbr_negative(nb % radix, radix, base);
	}
}

void	ft_rec_putnbr(int nb, int radix, char *base)
{
	if (nb < radix)
	{
		write(1, &base[nb], 1);
	}
	else
	{
		ft_rec_putnbr(nb / radix, radix, base);
		ft_rec_putnbr(nb % radix, radix, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	if (is_invalid(base, &radix))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_rec_putnbr_negative(-1 * nbr, radix, base);
	}
	else
		ft_rec_putnbr(nbr, radix, base);
}
