/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:28:15 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 11:55:56 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

int	dp_min(int **dp, int i, int j)
{
	return (get_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]));
}

int	get_min(int v1, int v2, int v3)
{
	if (v1 <= v2 && v1 <= v3)
		return (v1);
	else if (v2 <= v1 && v2 <= v3)
		return (v2);
	else
		return (v3);
}

int	is_printable(char ch)
{
	if (32 <= ch && ch <= 126)
		return (1);
	return (0);
}

int	is_valid_charset(t_node *data)
{
	if (!is_printable(data->empty))
		return (0);
	if (!is_printable(data->obstacle))
		return (0);
	if (!is_printable(data->full))
		return (0);
	if (data->empty == data->obstacle)
		return (0);
	if (data->full == data->obstacle)
		return (0);
	if (data->full == data->empty)
		return (0);
	return (1);
}
