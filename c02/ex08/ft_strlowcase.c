/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:51:12 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/21 20:51:14 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ('A' <= str[idx] && str[idx] <= 'Z')
			str[idx] += 'a' - 'A';
		++idx;
	}
	return (str);
}
