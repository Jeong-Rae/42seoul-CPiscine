/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:48:02 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 17:44:26 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_out.h"

void	translate(t_list *init_h, t_ull key)
{
	translate_billion(init_h, key);
}

void	translate_billion(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h;
	if (key == 0)
	{
		print_node(init_h, 0);
		write(1, "\n", 1);
		return ;
	}
	while (p->next && p->next->key >= 10000 && key >= 10000)
	{
		p = p->next;
		if (key >= p->key)
		{
			if (key / p->key != 1 || key >= 100000000)
				translate_1_999(init_h, key / p->key);
			print_node(init_h, p->key);
			write(1, " ", 1);
			key %= p->key;
		}
	}
	if (key < 10000)
		translate_1_999(init_h, key);
	write(1, "\n", 1);
}

void	translate_1_999(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h;
	while (p->next)
	{
		p = p->next;
		if (key == 0)
			return ;
		else if (key >= p->key)
		{
			if (key / p->key != 1)
				print_node(init_h, key / p->key);
			print_node(init_h, p->key);
			key %= p->key;
		}
	}
}

void	print_node(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h->next;
	while (p->key != key)
		p = p->next;
	ft_putstr(p->value);
}
