/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:56:02 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/07 15:20:51 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	(*ops[5])(int, int);

	if (argc != 4)
		return (0);
	ops[0] = ft_add;
	ops[1] = ft_sub;
	ops[2] = ft_mul;
	ops[3] = ft_div;
	ops[4] = ft_mod;
	if (get_op(argv[2]) == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_calc(ft_atoi(argv[1]), ft_atoi(argv[3]), ops[get_op(argv[2])]);
	return (0);
}
