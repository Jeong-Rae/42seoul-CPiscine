/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:32:57 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 22:04:59 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_itoa_base(long long nbr, char *base, long long radix, char *answer);

int	is_invalid(char *base, int *len)
{
	int	idx;
	int	flag;
	int	j;

	idx = 0;
	flag = 0;
	while (base[idx])
	{
		if (base[idx] == '+' || base[idx] == '-' || base[idx] == '\n'
			|| base[idx] == '\t' || base[idx] == '\v' || base[idx] == '\f'
			|| base[idx] == '\r' || base[idx] == ' ')
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

char	*atoi_conditon(char *str, int *sign)
{
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		++str;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base, int radix)
{
	int	sign;
	int	result;
	int	idx;

	sign = 1;
	str = atoi_conditon(str, &sign);
	result = 0;
	while (*str)
	{
		idx = 0;
		while (*str != base[idx] && idx < radix)
			++idx;
		if (idx >= radix)
			return (sign * result);
		result = result * radix + idx;
		++str;
	}
	return (sign * result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		in_radix;
	int		out_radix;
	int		temp;
	char	*answer;

	answer = (char *)malloc(sizeof(char) * 34);
	if (!answer)
		return (0);
	if (is_invalid(base_from, &in_radix) || is_invalid(base_to, &out_radix))
		return (0);
	temp = ft_atoi_base(nbr, base_from, in_radix);
	ft_itoa_base((long long)temp, base_to, (long long)out_radix, answer);
	return (answer);
}
