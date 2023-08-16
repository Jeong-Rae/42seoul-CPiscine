/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:23:35 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/19 21:34:11 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combn(char answer[], int index, char value, int n )
{
	char	*comma;
	char	m;

	comma = ", ";
	if (index == n)
	{
		m = 10 - n + '0';
		write(1, answer, n);
		if (answer[0] != m)
			write(1, comma, 2);
		return ;
	}
	if (value > '9')
		return ;
	answer[index] = value;
	print_combn(answer, index + 1, value + 1, n);
	print_combn(answer, index, value + 1, n);
}

void	ft_print_combn(int n)
{
	char	answer[9];

	print_combn(answer, 0, '0', n);
}


a = 0
while (a < 10)
{
	a++ ;
}

w(int* a)
{
	if(a==9)
		return;
	a++;
	w(int* a)
}
