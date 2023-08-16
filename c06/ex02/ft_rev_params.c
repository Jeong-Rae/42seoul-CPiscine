/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:42:08 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/27 14:44:56 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	main(int argc, char **argv)
{
	while (0 < --argc)
	{
		write(1, argv[argc], ft_strlen(argv[argc]));
		write(1, "\n", 1);
	}
	return (0);
}
