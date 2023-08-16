/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:12:23 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/20 19:19:05 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (!*str)
		return (1);
	while (*str)
	{
		if (*str < 'A' || ('Z' < *str && *str < 'a') || 'z' < *str)
			return (0);
		++str;
	}
	return (1);
}
