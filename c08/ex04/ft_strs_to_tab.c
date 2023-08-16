/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:46:36 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/01 07:46:37 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*cp;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	cp = dest;
	while (*src)
	{
		*cp = *src;
		++ cp;
		++ src;
	}
	cp = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		++ i;
	}
	tab[i].str = 0;
	return (tab);
}
