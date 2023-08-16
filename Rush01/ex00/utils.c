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
#	include <unistd.h>
#	define N 4

void	print_board(int board[N + 2][N + 2])
{
	int		i;
	int		j;
	char	ch;

	i = 1;
	while (i <= N)
	{
		j = 1;
		while (j <= N)
		{
			ch = board[i][j] + '0';
			write(1, &ch, 1);
			if (j < N)
				write(1, " ", 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}

void	set_zero_board(int board[N + 2][N + 2])
{
	int		i;
	int		j;

	i = 1;
	while (i <= N)
	{
		j = 1;
		while (j <= N)
		{
			board[i][j] = 0;
			j ++;
		}
		i ++;
	}
}

void	set_board(int board[N + 2][N + 2], char *argv)
{
	int	i;

	i = 0;
	set_zero_board(board);
	while (++ i <= 4)
		board[0][i] = argv[(i - 1) * 2] - '0';
	i = 0;
	while (++ i <= 4)
		board[N + 1][i] = argv[(i + 3) * 2] - '0';
	i = 0;
	while (++ i <= 4)
		board[i][0] = argv[(i + 7) * 2] - '0';
	i = 0;
	while (++ i <= 4)
		board[i][N + 1] = argv[(i + 11) * 2] - '0';
}

int	check_argv(char *argv)
{
	int		len;
	char	prev;

	len = 0;
	prev = ' ';
	while (argv[len])
	{
		if (('1' <= prev && prev <= '4' && argv[len] == ' ')
			|| (prev == ' ' && '1' <= argv[len] && argv[len] <= '4'))
		{
			prev = argv[len];
			len ++;
		}
		else
			return (0);
	}
	if (argv[len - 1] < '0' || argv[len - 1] > '4' || (len != 31))
		return (0);
	return (1);
}
