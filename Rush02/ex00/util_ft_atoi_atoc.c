/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ft_atoi_atoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwanki <jihwanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:56:02 by jihwanki          #+#    #+#             */
/*   Updated: 2023/08/06 16:39:11 by jihwanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_dict.h"

long long	ft_atoi_while(char *str, int order, int minus, long long result)
{
	while (*str)
	{
		if (order <= 0 && (*str == ' ' || (9 <= *str && *str <= 13)))
			order = 0;
		else if ((order <= 1 && *str == '-') || (order <= 1 && *str == '+'))
		{
			if (order == 1)
				break ;
			order = 1;
			if (*str == '-')
				minus *= -1;
		}
		else if (order <= 2 && '0' <= *str && *str <= '9')
		{
			order = 2;
			result = result * 10 + (*str - '0');
		}
		else
			break ;
		str += 1;
	}
	if (order < 2)
		return (-1);
	return (result * minus);
}

long long	ft_atoi(char *str)
{
	int			order;
	int			minus;
	long long	result;

	order = -1;
	minus = 1;
	result = 0;
	result = ft_atoi_while(str, order, minus, result);
	if (result < 0)
		return (-1);
	else
		return (result);
}

int	ft_str_is_printable(unsigned char *str)
{
	while (*str)
	{
		if (*str < 32 || 126 < *str)
			return (0);
		str += 1;
	}
	return (1);
}

unsigned char	*ft_atoc(unsigned char *str)
{
	unsigned char	**words;
	int				size;
	unsigned char	*result;
	int				i;

	if (ft_str_is_printable(str) == 0)
		return (0);
	words = ft_split(str, " ");
	size = 0;
	i = 0;
	while (words[i] != 0)
	{
		size += 1;
		i += 1;
	}
	result = ft_strjoin(size, words, " ");
	i = 0;
	while (i <= size)
		free(words[i++]);
	free(words);
	return (result);
}
