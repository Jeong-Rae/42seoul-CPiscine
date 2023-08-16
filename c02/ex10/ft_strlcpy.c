/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:09:26 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/21 21:24:41 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	idx = 0;
	while (idx + 1 < size && src[idx])
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = '\0';
	return (src_len);
}
