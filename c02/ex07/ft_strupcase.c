/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:26:24 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/21 20:26:26 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ('a' <= str[idx] && str[idx] <= 'z')
			str[idx] -= 'a' - 'A';
		++idx;
	}
	return (str);
}
