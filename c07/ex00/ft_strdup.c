/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:54:49 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/27 17:02:26 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		idx;
	int		size;

	idx = 0;
	size = ft_strlen(src) + 1;
	str = (char *)malloc(size);
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
