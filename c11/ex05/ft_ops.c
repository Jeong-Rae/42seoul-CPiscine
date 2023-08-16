/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:54:04 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 21:11:16 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_add(int v1, int v2)
{
	return (v1 + v2);
}

int	ft_sub(int v1, int v2)
{
	return (v1 - v2);
}

int	ft_mul(int v1, int v2)
{
	return (v1 * v2);
}

int	ft_div(int v1, int v2)
{
	return (v1 / v2);
}

int	ft_mod(int v1, int v2)
{
	return (v1 % v2);
}
