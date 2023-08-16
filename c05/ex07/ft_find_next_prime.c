/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:41:59 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 23:42:05 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	unsigned int	factor;
	unsigned int	unb;

	if (nb < 2)
		return (0);
	unb = (unsigned)nb;
	factor = 2;
	while (factor * factor <= unb)
	{
		if (!(unb % factor))
			return (0);
		++factor;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb)
	{
		if (is_prime(nb))
			return (nb);
		++nb;
	}
	return (nb);
}
