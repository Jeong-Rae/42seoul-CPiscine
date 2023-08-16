/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choolee <choolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:34:09 by choolee           #+#    #+#             */
/*   Updated: 2023/07/23 16:03:07 by choolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_conditions00(int xi, int yi, int x, int y)
{
	if ((xi == 1 && yi == 1) || (xi == x && yi == 1))
		ft_putchar('o');
	else if ((xi == 1 && yi == y) || (xi == x && yi == y))
		ft_putchar('o');
	else if (xi == 1 || xi == x)
		ft_putchar('|');
	else if (yi == 1 || yi == y)
		ft_putchar('-');
	else
		ft_putchar(' ');
}

int	str_to_int(char *str)
{
	int	result;
	int	index;
	int	sign;

	result = 0;
	index = 0;
	sign = 1;
	if (str[index] == '-')
	{
		sign = -1;
		++index;
	}
	while (str[index] != '\0')
	{
		if ((str[index] - '0' < 0) || (str[index] - '0' > 9))
			return (-1);
		result = result * 10 + (str[index] - '0');
		++index;
	}
	return (result * sign);
}

int	rush00(int x, int y)
{
	int	xi;
	int	yi;

	xi = 1;
	yi = 1;
	if (x < 1 || y < 1)
		return (0);
	while (yi <= y)
	{
		check_conditions00(xi, yi, x, y);
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
