/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 06:59:24 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/09 21:22:16 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

void	print_board(char **board, t_node *node)
{
	int	i;

	i = 0;
	while (i < node->n)
	{
		write(1, board[i], node->m);
		write(1, "\n", 1);
		i ++;
	}
}

char	**set_board(t_node *node)
{
	int		i;
	char	**board;

	i = 0;
	board = (char **)malloc(sizeof(char *) * node->n);
	while (i < node->n)
		board[i ++] = (char *)malloc(sizeof(char) * node->m);
	return (board);
}

void	free_board(char **board, t_node *board_data)
{
	int	i;

	i = 0;
	while (i < board_data->n)
		free(board[i ++]);
	free(board);
}

void	set_init_data(t_node *board_data)
{
	board_data->empty = 0;
	board_data->full = 0;
	board_data->obstacle = 0;
	board_data->m = 0;
	board_data->n = 0;
	board_data->max_x = 0;
	board_data->max_y = 0;
	board_data->max_length = 0;
}
