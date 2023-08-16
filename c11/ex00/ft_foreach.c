/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:18:46 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 19:22:49 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int legth, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < legth)
		f(tab[i ++]);
}
