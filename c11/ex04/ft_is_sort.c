/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:45:23 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/08 10:20:28 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_sort;
	int	i;

	i = 0;
	is_sort = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (!is_sort)
				is_sort = -1;
			else if (is_sort > 0)
				return (0);
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (!is_sort)
				is_sort = 1;
			else if (is_sort < 0)
				return (0);
		}
		i ++;
	}
	return (1);
}
