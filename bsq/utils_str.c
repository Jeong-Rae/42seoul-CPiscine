/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:54:30 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 11:26:18 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(char *src, int size)
{
	char	*str;
	int		idx;

	idx = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (idx < size)
	{
		str[idx] = src[idx];
		++idx;
	}
	str[idx] = '\0';
	return (str);
}

int	ft_atoi(char *str)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			result = 10 * result + *str - '0';
		else
			return (0);
		++str;
	}
	return (sign * result);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 == s2 && *s1 && *s2)
	{
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}
