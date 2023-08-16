/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_putstr_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:09:21 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 02:22:45 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_out.h"

void	ft_putstr_s(unsigned char *str)
{
	write(1, " ", 1);
	while (*str)
		write(1, str ++, 1);
}

void	ft_putstr_h(unsigned char *str)
{
	while (*str)
		write(1, str ++, 1);
	write(1, "-", 1);
}

void	ft_putstr(unsigned char *str)
{
	while (*str)
		write(1, str ++, 1);
}
