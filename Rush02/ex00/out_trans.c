/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:48:02 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 13:01:23 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_out.h"

void	translate(t_list *init_h, t_ull key)
{
	if (key / 1000000000 >= 1000)
	{
		translate_billion(init_h, key / 1000000000);
		print_node(init_h, 1000000000);
		if (key % 1000000000 != 0)
		{
			write(1, ", ", 2);
			translate_billion(init_h, key % 1000000000);
		}
	}
	else
		translate_billion(init_h, key);
	write(1, "\n", 1);
}

void	translate_billion(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h;
	if (key == 0)
	{
		print_node(init_h, 0);
		return ;
	}
	while (p->next && p->next->key >= 1000 && key >= 1000)
	{
		p = p->next;
		if (key >= p->key)
		{
			translate_1_999(init_h, key / p->key);
			print_node(init_h, p->key);
			key %= p->key;
			if (key != 0)
				write(1, ", ", 2);
		}
	}
	if (key < 1000)
		translate_1_999(init_h, key);
}

void	translate_1_999(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h;
	while (p->next)
	{
		p = p->next;
		if (key >= 100)
		{
			print_node(init_h, key / 100);
			print_node(init_h, 100);
			key %= 100;
			if (key > 0)
				write(1, " and ", 5);
		}
		else if (key == 0)
			return ;
		else if (key >= p->key)
		{
			print_node(init_h, p->key);
			key %= p->key;
			if (9 >= key && key > 0)
				write(1, "-", 1);
		}
	}
}

void	print_node(t_list *init_h, t_ull key)
{
	t_list	*p;

	p = init_h->next;
	while (p->key != key)
		p = p->next;
	if (p->key >= 100)
		ft_putstr_s(p->value);
	else
		ft_putstr(p->value);
}
