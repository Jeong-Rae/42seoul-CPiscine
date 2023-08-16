/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:54:25 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 22:01:18 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p;
	char	*start;
	char	*target;

	p = str;
	while (*p)
	{
		start = p;
		target = to_find;
		while (*start == *target && *target)
		{
			++start;
			++target;
		}
		if (!(*target))
			return (p);
		++p;
	}
	if (!(*to_find))
		return (str);
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char dest[10] = "hello";
	char src[3] = "ll";
	printf("%s",ft_strstr(dest,src));
	return 0;

}
