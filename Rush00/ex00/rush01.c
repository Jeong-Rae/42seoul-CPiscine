/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:26:35 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/22 18:28:52 by choolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	check_conditions01(int x, int y, int xi, int yi)
{
	if ((yi == y && x == 1) || (xi == x && y == 1))
	{
		if (x == y)
		{
			ft_putchar('/');
			return ;
		}
		ft_putchar('\\');
		return ;
	}
	if ((yi == 1 && xi == 1) || (yi == y && xi == x))
		ft_putchar('/');
	else if ((yi == 1 && xi == x) || (yi == y && xi == 1))
		ft_putchar('\\');
	else if (yi == 1 || yi == y || xi == 1 || xi == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

int	rush01(int x, int y)
{
	int	xi;
	int	yi;

	xi = 1;
	yi = 1;
	if (x < 1 || y < 1)
	{
		return (0);
	}
	while (yi <= y)
	{
		check_conditions01(x, y, xi, yi);
		xi++;
		if (xi > x)
		{
			xi = 1;
			yi++;
			ft_putchar('\n');
		}
	}
	return (0);
}
