/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:20:48 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 21:24:41 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char	*dest, char *src)
{
	char	*p;

	p = dest;
	while (*p)
	{
		++p;
	}
	while (*src)
	{
		*p = *src;
		++p;
		++src;
	}
	*p = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char dest[10] = "hello";
	char src[3] = "hi";
	printf("%s",strcat(dest,src));
	return 0;

}
