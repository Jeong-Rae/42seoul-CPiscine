/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:35:31 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/20 11:45:50 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index <= size - 1)
	{
		temp = tab[index];
		tab[index] = tab[size - 1];
		tab[size - 1] = temp;
		++index;
		--size;
	}
}
