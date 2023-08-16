/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:51:08 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 16:17:39 by choolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	rush00(int x, int y);
int	rush01(int x, int y);
int	rush02(int x, int y);
int	rush03(int x, int y);
int	rush04(int x, int y);
int	str_to_int(char *str);

int	main(int argc, char *argv[])
{
	int	n;
	int	x;
	int	y;

	n = str_to_int(argv[1]);
	x = str_to_int(argv[2]);
	y = str_to_int(argv[3]);
	if (!(n >= 0 && n <= 4) || (x < 1) || (y < 1))
		write (1, "invalid input", 14);
	if (n == 0)
		rush00(x, y);
	else if (n == 1)
		rush01(x, y);
	else if (n == 2)
		rush02(x, y);
	else if (n == 3)
		rush03(x, y);
	else if (n == 4)
		rush04(x, y);
	argc = 0;
	return (0);
}
