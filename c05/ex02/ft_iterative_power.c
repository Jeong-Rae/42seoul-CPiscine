/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_power.c                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:03:30 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 20:11:54 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	answer = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power - 1)
	{
		answer *= nb;
		--power;
	}
	return (answer);
}
