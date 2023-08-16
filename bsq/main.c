/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:24:00 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 11:51:00 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*filename;
	int		i;

	if (argc == 1)
	{
		if (std_input_case(0) < 1)
			write(2, "map error\n", 10);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			filename = argv[i];
			if (input_maps_case(filename) < 1)
				write(2, "map error\n", 10);
			if (i <= argc - 2)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
