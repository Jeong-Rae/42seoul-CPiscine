/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 07:08:34 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 12:19:23 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

int	get_board_info(int fd, t_node *board_data)
{
	t_vector	*v;
	char		buf[1];

	v = create_vector();
	while (1)
	{
		if (read(fd, buf, 1) == 0 || buf[0] == '\n')
			break ;
		push_back(v, buf[0]);
	}
	if (v->len < 4)
	{
		free_vector(v);
		return (0);
	}
	board_data->full = v->arr[v->len - 1];
	board_data->obstacle = v->arr[v->len - 2];
	board_data->empty = v->arr[v->len - 3];
	v->arr[v->len - 3] = 0;
	board_data->n = ft_atoi(v->arr);
	free_vector(v);
	if (board_data->n <= 0 || !is_valid_charset(board_data))
		return (0);
	return (1);
}

int	get_board_first_line(char **board, int fd, t_node *board_data)
{
	t_vector	*v;
	char		buf[1];

	v = create_vector();
	while (1)
	{
		if (read(fd, buf, 1) == 0)
		{
			free_vector(v);
			return (0);
		}
		if (buf[0] == '\n')
			break ;
		push_back(v, buf[0]);
	}
	board_data->m = v->len;
	board[0] = ft_strdup(v->arr, board_data->m);
	free_vector(v);
	if (!board[0])
		return (0);
	return (1);
}

int	get_board_another_line(char **board, int fd, t_node *board_data)
{
	int			i;
	char		ch[1];

	i = 1;
	while (i < board_data->n)
	{
		board[i] = (char *)malloc((board_data->m) * sizeof(char));
		if (!board[i])
			return (0);
		if (read(fd, board[i], board_data->m) == 0 && i + 1 < board_data->n)
		{
			return (0);
		}
		read(fd, ch, 1);
		if (*ch != '\n')
			return (-1 * i);
		*ch = 0;
		i ++;
	}
	if (read(fd, ch, 1) != 0)
		return (-1 * board_data->n);
	return (1);
}
