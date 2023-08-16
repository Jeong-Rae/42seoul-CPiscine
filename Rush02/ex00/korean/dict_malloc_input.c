/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_malloc_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwanki <jihwanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:01:33 by jihwanki          #+#    #+#             */
/*   Updated: 2023/08/06 17:52:00 by jihwanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_dict.h"

int	is_key_duplicate(long long line_len, long long *key)
{
	int	i;
	int	j;

	i = 0;
	while (i < line_len)
	{
		j = i + 1;
		while (j < line_len)
		{
			if (key[i] == key[j])
				return (-1);
			j += 1;
		}
		i += 1;
	}
	return (0);
}

void	input_key_len(char *filename, int *key_len)
{
	int				fd;
	unsigned char	c;
	int				len;
	int				is_key;

	fd = open(filename, O_RDONLY);
	len = 0;
	is_key = 1;
	while (read(fd, &c, 1))
	{
		if (c == ':')
			is_key = 0;
		if (is_key == 1)
			len += 1;
		if (c == '\n' && is_key == 0)
		{
			*(key_len++) = len;
			len = 0;
			is_key = 1;
		}
	}
	close(fd);
}

void	input_value_len(char *filename, int *value_len)
{
	int				fd;
	unsigned char	c;
	int				len;
	int				is_value;

	fd = open(filename, O_RDONLY);
	len = 0;
	is_value = 0;
	while (read(fd, &c, 1))
	{
		if (c == ':')
			is_value = 1;
		else if (is_value == 1)
			len += 1;
		if (c == '\n' && is_value == 1)
		{
			*(value_len++) = len - 1;
			len = 0;
			is_value = 0;
		}
	}
	close(fd);
}

long long	*malloc_input_key(char *filename)
{
	long long		*key;
	const long long	line_len = file_line_len(filename);

	if (line_len <= 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	key = (long long *)malloc(sizeof(long long) * line_len);
	if (key == NULL)
		return (0);
	if (input_key(filename, key) == -1 || is_key_duplicate(line_len, key) == -1)
	{
		write(1, "Dict Error\n", 11);
		free(key);
		return (0);
	}
	return (key);
}

unsigned char	**malloc_input_value(char *filename)
{
	unsigned char	**value;
	const long long	line_len = file_line_len(filename);

	if (line_len <= 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	value = (unsigned char **)malloc(sizeof(char *) * (line_len + 1));
	if (value == NULL)
		return (0);
	value[line_len] = 0;
	if (input_value(filename, value) == -1)
	{
		write(1, "Dict Error\n", 11);
		free(value);
		return (0);
	}
	return (value);
}
