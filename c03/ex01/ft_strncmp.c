/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:45:06 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 20:14:00 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;
	int				result;

	idx = 0;
	result = 0;
	while (!result && idx < n && (s1[idx] && s2[idx]))
	{
		result = (unsigned char)s1[idx] - (unsigned char)s2[idx];
		++idx;
	}
	if (!result && idx < n)
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
	printf("%d",ft_strncmp("hello","hi",2));
	printf("%d",strncmp("hello","hi",2));
	return 0;ds

}

