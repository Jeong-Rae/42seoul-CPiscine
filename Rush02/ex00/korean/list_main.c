/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:41:52 by yojin             #+#    #+#             */
/*   Updated: 2023/08/06 05:58:59 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_list.h"
#include "rush_out.h"

t_list	*init_list(long long *keys, unsigned char **values)
{
	t_list	*header;
	int		i;

	header = (t_list *)malloc(sizeof(t_list));
	if (!header)
		return (0);
	header->flag = 2;
	header->next = 0;
	header->key = 0;
	i = 0;
	init_initial_keys(header);
	while (values[i])
	{
		update_key(header, (t_ull)keys[i], values[i]);
		i++;
	}
	if (check_initial_keys(header) == 0)
		return (0);
	return (header);
}

t_list	*insert(t_list *header, t_ull key, unsigned char *value)
{
	t_list	*node;
	t_list	*new_node;

	if (!header)
		return (0);
	node = header;
	while (node->next && node->next->key > key)
		node = node->next;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->key = key;
	new_node->value = value;
	new_node->flag = 0;
	new_node->next = node->next;
	node->next = new_node;
	return (new_node);
}

void	free_list(t_list *header)
{
	t_list	*node;
	t_list	*temp;

	if (!header)
		return ;
	node = header;
	while (node->next)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(node);
}
