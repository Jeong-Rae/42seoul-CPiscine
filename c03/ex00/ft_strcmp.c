/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:10:27 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 17:12:49 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;
	int	result;

	idx = 0;
	result = 0;
	while (!result && (s1[idx] && s2[idx]))
	{
		result = (unsigned char)s1[idx] - (unsigned char)s2[idx];
		++idx;
	}
	if (!result)
		result = (unsigned char)s1[idx] - (unsigned char)s2[idx];
	if (result < 0)
		return (-1);
	else if (result > 0)
		return (1);
	else
		return (0);
}
#include <stdio.h>
#include <string.h>
int main()
{
	char dest[6] = "hello";
	char src[3] = "hi";
	printf("%d",ft_strcmp(dest,src));
	printf("%d",strcmp(dest,src));
	return 0;

}
