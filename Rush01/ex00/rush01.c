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

int		is_valid_counts(int board[N + 2][N + 2], int row, int col);
int		is_duplicated(int board[N + 2][N + 2], int row, int col, int value);
void	print_board(int board[N + 2][N + 2]);
int		check_argv(char *argv);
void	set_board(int board[N + 2][N + 2], char *argv);

void	dfs(int board[][N + 2], int level)
{
	int	next;

	if (board[0][0])
		return ;
	if (level == N * N)
	{
		board[0][0] = 1;
		print_board(board);
		return ;
	}
	if (board[level / N + 1][level % N + 1] != 0)
		dfs(board, level + 1);
	next = 0;
	while (++ next <= N)
	{
		if (is_duplicated(board, level / N + 1, level % N + 1, next))
			continue ;
		board[level / N + 1][level % N + 1] = next;
		if (is_valid_counts(board, level / N + 1, level % N + 1))
			dfs(board, level + 1);
		board[level / N + 1][level % N + 1] = 0;
	}
}

int	main(int argc, char **argv)
{
	int	board[N + 2][N + 2];

	if (argc == 2)
	{
		if (!check_argv(argv[1]))
		{
			write(1, "Error\n", 7);
			return (0);
		}
		set_board(board, argv[1]);
		dfs(board, 0);
		if (!board[0][0])
			write(1, "Error\n", 7);
	}
	else
		write(1, "Error\n", 7);
	return (0);
}
