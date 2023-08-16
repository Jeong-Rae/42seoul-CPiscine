/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:48:27 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 19:56:17 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	answer;

	answer = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		answer *= nb;
		nb --;
	}
	return (answer);
}
