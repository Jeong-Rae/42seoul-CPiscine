/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:56:26 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/20 19:02:27 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		idx;

	idx = 0;
	while (src[idx])
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = '\0';
	return (dest);
}
