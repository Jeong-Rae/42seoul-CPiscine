/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:25 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/27 11:25:07 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;

	len = my_strlen(argv[0]);
	write(1, argv[0], len);
	write(1, "\n", 1);
	argc = 0;
	return (0);
}
