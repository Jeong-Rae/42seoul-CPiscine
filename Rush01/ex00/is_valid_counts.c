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

int	get_count_left_visable(int board[N + 2][N + 2], int row)
{
	int	max_h;
	int	cnt;
	int	i;

	max_h = 0;
	cnt = 0;
	i = 0;
	while (++ i <= N)
	{
		if (board[row][i] > max_h)
		{
			max_h = board[row][i];
			cnt ++;
		}
	}
	return (cnt);
}

int	get_count_right_visable(int board[N + 2][N + 2], int row)
{
	int	max_h;
	int	cnt;
	int	i;

	max_h = 0;
	cnt = 0;
	i = N + 1;
	while (-- i >= 1)
	{
		if (board[row][i] > max_h)
		{
			max_h = board[row][i];
			cnt ++;
		}
	}
	return (cnt);
}

int	get_count_up_visable(int board[N + 2][N + 2], int col)
{
	int	max_h;
	int	cnt;
	int	i;

	max_h = 0;
	cnt = 0;
	i = 0;
	while (++ i <= N)
	{
		if (board[i][col] > max_h)
		{
			max_h = board[i][col];
			cnt ++;
		}
	}
	return (cnt);
}

int	get_count_down_visable(int board[N + 2][N + 2], int col)
{
	int	max_h;
	int	cnt;
	int	i;

	max_h = 0;
	cnt = 0;
	i = N + 1;
	while (-- i >= 1)
	{
		if (board[i][col] > max_h)
		{
			max_h = board[i][col];
			cnt ++;
		}
	}
	return (cnt);
}

int	is_valid_counts(int board[N + 2][N + 2], int row, int col)
{
	if (col == N)
	{
		if (get_count_left_visable(board, row) != board[row][0])
			return (0);
		if (get_count_right_visable(board, row) != board[row][N + 1])
			return (0);
	}
	if (row == N)
	{
		if (get_count_up_visable(board, col) != board[0][col])
			return (0);
		if (get_count_down_visable(board, col) != board[N + 1][col])
			return (0);
	}
	if (get_count_left_visable(board, row) > board[row][0])
		return (0);
	if (get_count_up_visable(board, col) > board[0][col])
		return (0);
	return (1);
}
