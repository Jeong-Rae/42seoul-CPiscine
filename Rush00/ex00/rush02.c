/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehyuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:15:23 by daehyuki          #+#    #+#             */
/*   Updated: 2023/07/22 17:08:07 by daehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_conditions02(int xi, int yi, int x, int y)
{
	if ((xi == 1 && yi == 1) || (xi == x && yi == 1))
	{
		ft_putchar('A');
	}
	else if ((xi == 1 && yi == y) || (xi == x && yi == y))
	{
		ft_putchar('C');
	}
	else if (xi == 1 || xi == x || yi == 1 || yi == y)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

int	rush02(int x, int y)
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
		check_conditions02(xi, yi, x, y);
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
