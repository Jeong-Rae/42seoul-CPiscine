/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:08:14 by gyeolee           #+#    #+#             */
/*   Updated: 2023/08/09 17:58:41 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

char	**allocate_file_name(int argc, char *argv[])
{
	char	**file_name;
	int		i;

	file_name = (char **)malloc((argc - 1) * sizeof(char *));
	if (file_name == 0)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		file_name[i] = argv[i + 1];
		i++;
	}
	return (file_name);
}

char	*ft_realloc(char *ptr, unsigned int size)
{
	char	*new;
	int		i;

	new = (char *)malloc(size * sizeof(char));
	if (new == 0)
		return (new);
	i = 0;
	while (ptr[i])
	{
		new[i] = ptr[i];
		i++;
	}
	new[i] = ptr[i];
	free(ptr);
	return (new);
}

int	**make_dp_arr(t_node *node)
{
	int	**dp;
	int	i;

	i = 0;
	dp = (int **)malloc(sizeof(int *) * node->n);
	if (!dp)
		return (0);
	while (i < node->n)
	{
		dp[i ++] = (int *)malloc(sizeof(int) * node->m);
		if (!dp[i - 1])
			return (0);
	}
	return (dp);
}

void	free_dp_arr(int **dp, t_node *node)
{
	int	i;

	i = 0;
	while (i < node->n)
		free(dp[i ++]);
	free(dp);
}
