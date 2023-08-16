/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:00:20 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 21:35:30 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

void	ft_calc(int v1, int v2, int (*f)(int, int))
{
	if (f == ft_div && v2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	else if (f == ft_mod && v2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(f(v1, v2));
	write(1, "\n", 1);
}
