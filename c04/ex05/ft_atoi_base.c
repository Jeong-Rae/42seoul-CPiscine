/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:26:12 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 18:26:16 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	radix;
	int	idx;

	sign = 1;
	if (is_invalid(base, &radix))
		return (0);
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
