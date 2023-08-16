/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:58:13 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 21:20:11 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

int		ft_atoi(char *str);
int		ft_add(int v1, int v2);
int		ft_sub(int v1, int v2);
int		ft_mul(int v1, int v2);
int		ft_div(int v1, int v2);
int		ft_mod(int v1, int v2);
int		get_op(char *str);
void	ft_calc(int v1, int v2, int (*f)(int, int));
void	ft_putnbr(int nbr);
void	ft_putchar(char ch);
int		ft_strcmp(char *s1, char *s2);

#endif
