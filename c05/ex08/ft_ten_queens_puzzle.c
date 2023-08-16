/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:53:11 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/27 01:53:14 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	print_board(char board[])
{
	write(1, board, 10);
	write(1, "\n", 1);
}

int	is_valid(char board[], int index, char value)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if ((board[i] == value) || (index - i == value - board[i])
			|| (index - i == board[i] - value))
			return (0);
		++i;
	}
	return (1);
}

void	dfs(char board[], int *count, int level, char value)
{
	char	next;

	board[level] = value;
	if (level == 9)
	{
		print_board(board);
		(*count) ++;
		return ;
	}
	next = '0';
	while (next <= '9')
	{
		if (is_valid(board, level + 1, next))
			dfs(board, count, level + 1, next);
		++ next;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		count;
	int		start;

	count = 0;
	start = '0';
	while (start <= '9')
	{
		dfs(board, &count, 0, start);
		++ start;
	}
	return (count);
}


#	include <stdio.h>
int main()
{
	printf("%d",ft_ten_queens_puzzle());
}

