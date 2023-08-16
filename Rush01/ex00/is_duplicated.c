/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:34:23 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/28 20:34:25 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#	define N 4

int	is_duplicated(int board[N + 2][N + 2], int row, int col, int value)
{
	int	i;

	i = 0;
	while (++ i <= N)
	{
		if (board[row][i] == value)
			return (1);
	}
	i = 0;
	while (++ i <= N)
	{
		if (board[i][col] == value)
			return (1);
	}
	return (0);
}
