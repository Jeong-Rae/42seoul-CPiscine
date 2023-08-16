/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:54:30 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/24 23:21:21 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
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
