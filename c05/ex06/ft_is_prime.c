/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:37:29 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/28 21:15:13 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
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

/* #include<unistd.h>
int main()
{
	write(1, "!", 1);
	ft_is_prime(2147483645);
	write(1, "!", 1);
	return (0);
} */
