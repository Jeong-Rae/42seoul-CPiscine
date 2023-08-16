/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:15:07 by yojin             #+#    #+#             */
/*   Updated: 2023/08/06 17:20:57 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_list.h"
#include "rush_out.h"

t_list	*init_initial_keys(t_list *header)
{
	int	i;

	if (!insert(header, 1000000000, 0))
		return (0);
	if (!insert(header, 1000000, 0) || !insert(header, 1000, 0))
		return (0);
	i = 100;
	while (i >= 30)
	{
		if (!insert(header, i, 0))
			return (0);
		i -= 10;
	}
	while (i >= 0)
		if (!insert(header, i--, 0))
			return (0);
	return (header);
}

t_list	*update_key(t_list *header, t_ull key, unsigned char *value)
{
	t_list	*node;

	node = header->next;
	while (node)
	{
		if (node->key == key)
		{
			node->value = value;
			node->flag = 1;
			return (node);
		}
		node = node->next;
	}
	return (0);
}

int	check_initial_keys(t_list *header)
{
	t_list	*node;

	node = header->next;
	while (node)
	{
		if (node->flag == 0)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		node = node->next;
	}
	return (1);
}
