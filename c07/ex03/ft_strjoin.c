/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:36:23 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 18:56:49 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		++dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = 0;
}

char	*ft_calloc(int size)
{
	char	*p;
	int		len;

	len = 0;
	p = (char *)malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	while (len < size + 1)
	{
		p[len] = 0;
		len ++;
	}
	return (p);
}

void	ft_interative_strcat(char *answer, char **strs, char *sep, int size)
{
	int	idx;

	idx = 0;
	while (idx < size - 1)
	{
		ft_strcat(answer, strs[idx]);
		ft_strcat(answer, sep);
		idx++;
	}
	ft_strcat(answer, strs[idx]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*answer;
	int		len;
	int		idx;

	len = 0;
	idx = -1;
	if (size == 0)
	{
		answer = (char *)malloc(sizeof(char));
		answer[0] = 0;
		return (answer);
	}
	while (++idx < size)
		len += ft_strlen(strs[idx]);
	len += ft_strlen(sep) * (size - 1);
	answer = ft_calloc(len);
	if (!answer)
		return (0);
	ft_interative_strcat(answer, strs, sep, size);
	return (answer);
}
