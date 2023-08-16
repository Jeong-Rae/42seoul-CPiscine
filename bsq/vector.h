/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:10:31 by gyeolee           #+#    #+#             */
/*   Updated: 2023/08/09 17:58:47 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define INITIAL_CAPACITY 16

typedef struct s_vector
{
	char			*arr;
	unsigned int	capacity;
	unsigned int	len;
}	t_vector;

t_vector	*create_vector(void);
int			push_back(t_vector *v, char c);
void		free_vector(t_vector *v);
char		**allocate_file_name(int argc, char *argv[]);
char		*ft_realloc(char *ptr, unsigned int size);

#endif
