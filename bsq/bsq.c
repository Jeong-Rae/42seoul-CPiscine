/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:28:56 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/09 23:26:50 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

int	set_dp(char **board, t_node *node, int **dp)
{
	int	i;
	int	j;

	i = 0;
	while (i < node->n)
	{
		j = 0;
		while (j < node->m)
		{
			dp[i][j] = 1;
			if (!(board[i][j] == node->empty || board[i][j] == node->obstacle))
				return (0);
			if (board[i][j] == node->obstacle)
				dp[i][j] = 0;
			else if (!(i == 0 || j == 0) && is_vaild_node(board, i, j, node))
				dp[i][j] = dp_min(dp, i, j) + 1;
			update_max_node(node, dp[i][j], i, j);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	is_vaild_node(char **board, int i, int j, t_node *node)
{
	if (board[i][j] != node->empty)
		return (0);
	if (board[i - 1][j] != node->empty)
		return (0);
	if (board[i][j - 1] != node->empty)
		return (0);
	if (board[i - 1][j - 1] != node->empty)
		return (0);
	return (1);
}

void	update_max_node(t_node *node, int value, int i, int j)
{
	if (node->max_length < value)
	{
		node->max_x = i;
		node->max_y = j;
		node->max_length = value;
	}
}

void	write_squre(char **board, t_node *node)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = node->max_x - node->max_length + 1;
	y = node->max_y - node->max_length + 1;
	i = 0;
	while (i < node->max_length)
	{
		j = 0;
		while (j < node->max_length)
		{
			board[x + i][y + j] = node->full;
			j ++;
		}
		i ++;
	}
}
