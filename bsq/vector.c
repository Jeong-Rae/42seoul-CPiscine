/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:02:03 by gyeolee           #+#    #+#             */
/*   Updated: 2023/08/10 11:56:19 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"

t_vector	*create_vector(void)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	if (new == 0)
		return (0);
	new->len = 0;
	new->capacity = INITIAL_CAPACITY;
	new->arr = (char *)malloc(new->capacity * sizeof(char));
	if (new ->arr == 0)
	{
		free(new);
		return (0);
	}
	new->arr[0] = 0;
	return (new);
}

int	push_back(t_vector *v, char c)
{
	char	*tmp;

	if (v->len == v->capacity - 1)
	{
		v->capacity *= 2;
		tmp = (char *)ft_realloc(v->arr, v->capacity);
		if (tmp == 0)
			return (-1);
		v->arr = tmp;
	}
	v->arr[v->len++] = c;
	v->arr[v->len] = '\0';
	return (0);
}

void	free_vector(t_vector *v)
{
	if (v)
	{
		if (v->arr)
			free(v->arr);
		free(v);
	}
}
