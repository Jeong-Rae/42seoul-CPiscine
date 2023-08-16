/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:28 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 19:51:53 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_itoa_base_r(long long nb, long long radix, char *base, char *answer)
{
	if (nb < radix)
	{
		while (*answer)
			answer++;
		*answer = base[nb];
		answer[1] = 0;
	}
	else
	{
		ft_itoa_base_r(nb / radix, radix, base, answer);
		ft_itoa_base_r(nb % radix, radix, base, answer);
	}
}

void	ft_itoa_base(long long nbr, char *base, long long radix, char *answer)
{
	if (nbr < 0)
	{
		*answer = '-';
		answer[1] = 0;
		ft_itoa_base_r(-1 * nbr, radix, base, answer);
	}
	else
	{
		*answer = 0;
		ft_itoa_base_r(nbr, radix, base, answer);
	}
}
