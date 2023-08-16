/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:04:09 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/20 19:10:52 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	len;
	int				flag;

	len = 0;
	flag = 0;
	while (len < n)
	{
		if (!flag)
		{
			dest[len] = src[len];
			if (src[len] == '\0')
				flag = 1;
		}
		else
			dest[len] = '\0';
		++len;
	}
	return (dest);
}
