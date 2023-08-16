/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:36:36 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/24 13:06:32 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		++len;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	idx;

	dest_len = ft_strlen(dest);
	dest += dest_len;
	src_len = ft_strlen(src);
	idx = 0;
	while (src[idx] && dest_len + idx + 1 < size)
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = 0;
	if (size < dest_len)
		return (src_len + size);
	return (src_len + dest_len);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char dest[10] = "hello";
	char src[3] = "ll";
	printf("%u",ft_strlcat(dest,src,2));
	return 0;

}
