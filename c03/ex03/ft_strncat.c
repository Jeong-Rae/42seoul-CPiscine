/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:36:17 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 21:47:50 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	char	*p;

	p = dest;
	while (*p)
		++p;
	while (n--)
	{
		*p = *src;
		if (!(*src))
			break ;
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
	printf("%s",ft_strncat(dest,src,1));
	return 0;

}
