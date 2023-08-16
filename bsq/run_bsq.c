/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bsq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:47:05 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 12:37:46 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	run_bsq(char **board, t_node *board_data)
{
	int		**dp;

	dp = make_dp_arr(board_data);
	if (!dp)
	{
		free_dp_arr(dp, board_data);
		return ;
	}
	if (set_dp(board, board_data, dp) == 0)
	{
		free_dp_arr(dp, board_data);
		write(2, "map error\n", 10);
		return ;
	}
	free_dp_arr(dp, board_data);
	write_squre(board, board_data);
	print_board(board, board_data);
}

int	input_3(char **board, int fd, t_node *board_data)
{
	int	index;
	int	i;

	if (get_board_first_line(board, fd, board_data) < 1)
		return (0);
	index = get_board_another_line(board, fd, board_data);
	if (index < 1)
	{
		i = 0;
		while (i < (index * -1))
		{
			free(board[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

int	input_2(int fd, t_node *board_data, char ***board)
{
	if (get_board_info(fd, board_data) < 1)
		return (0);
	*board = (char **)malloc(sizeof(char *) * board_data->n);
	if (!(*board))
		return (0);
	if (input_3(*board, fd, board_data) < 1)
	{
		free(*board);
		return (0);
	}
	return (1);
}

int	input_maps_case(char *filename)
{
	int		fd;
	char	**board;
	t_node	*board_data;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	board_data = (t_node *)malloc(sizeof(t_node));
	set_init_data(board_data);
	if (board_data == 0)
	{
		close(fd);
		return (0);
	}
	if (input_2(fd, board_data, &board) < 1)
	{
		close(fd);
		free(board_data);
		return (0);
	}
	run_bsq(board, board_data);
	free_board(board, board_data);
	free(board_data);
	close(fd);
	return (1);
}

int	std_input_case(int fd)
{
	char	**board;
	t_node	*board_data;

	if (fd < 0)
		return (0);
	board_data = (t_node *)malloc(sizeof(t_node));
	set_init_data(board_data);
	if (board_data == 0)
	{
		close(fd);
		return (0);
	}
	if (input_2(fd, board_data, &board) < 1)
	{
		close(fd);
		free(board_data);
		return (0);
	}
	run_bsq(board, board_data);
	free_board(board, board_data);
	free(board_data);
	close(fd);
	return (1);
}
