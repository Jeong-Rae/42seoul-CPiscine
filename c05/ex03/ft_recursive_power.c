/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:38:04 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 20:47:17 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	answer;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	answer = 1;
	return (nb * ft_recursive_power(nb, power - 1));
}
