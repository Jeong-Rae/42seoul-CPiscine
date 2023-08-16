/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_out.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:10:32 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 02:22:00 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_OUT_H
# define RUSH_OUT_H

# include "rush_list.h"

void	translate(t_list *init_h, t_ull key);
void	translate_billion(t_list *init_h, t_ull key);
void	translate_1_999(t_list *init_h, t_ull key);
void	print_node(t_list *init_h, t_ull key);
void	ft_putstr_s(unsigned char *str);
void	ft_putstr_h(unsigned char *str);
void	ft_putstr(unsigned char *str);

#endif
