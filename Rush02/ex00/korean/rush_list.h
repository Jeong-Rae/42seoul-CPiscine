/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:40:32 by yojin             #+#    #+#             */
/*   Updated: 2023/08/06 03:20:59 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_LIST_H
# define RUSH_LIST_H
# include <stdlib.h>
# include <unistd.h>
# define BILLION	1000000000
# define MILLION	1000000
# define THOUSAND	1000

typedef long long			t_ll;
typedef unsigned long long	t_ull;
typedef struct s_list
{
	int					flag;
	unsigned long long	key;
	unsigned char		*value;
	struct s_list		*next;
}	t_list;
t_list			*init_list(long long *key, unsigned char **value);
t_list			*init_initial_keys(t_list *header);
t_list			*update_key(t_list *header, t_ull key, unsigned char *value);
t_list			*insert(t_list *header, t_ull key, unsigned char *value);
int				check_initial_keys(t_list *header);
void			free_list(t_list *header);
void			print_list(t_list *header);

#endif
