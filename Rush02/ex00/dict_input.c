/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwanki <jihwanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:36:32 by jihwanki          #+#    #+#             */
/*   Updated: 2023/08/06 16:59:09 by jihwanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_dict.h"

int	file_line_len(char *filename)
{
	int				fd;
	long long		num_line;
	unsigned char	c;
	unsigned char	prev_c;
	long long		num_colons;

	fd = open(filename, O_RDONLY);
	num_line = 0;
	num_colons = 0;
	prev_c = '\0';
	while (read(fd, &c, 1))
	{
		if (c == ':')
			num_colons += 1;
		if (prev_c != '\n' && c == '\n')
		{
			num_line += 1;
			if (num_line != num_colons)
				return (-1);
		}
		prev_c = c;
	}
	close(fd);
	return (num_line);
}

long long	line_read_key(int *key_len, int *i, int fd)
{
	long long		key;
	unsigned char	*ascii_int;

	ascii_int = (unsigned char *)malloc(sizeof(char) * (key_len[*i] + 1));
	if (ascii_int == NULL)
		return (-1);
	read(fd, ascii_int, key_len[*i]);
	ascii_int[key_len[*i]] = '\0';
	key = ft_atoi((char *)ascii_int);
	while (read(fd, ascii_int, 1) && *ascii_int != '\n')
		;
	free(ascii_int);
	return (key);
}

int	input_key(char *filename, long long *key)
{
	int				fd;
	int				i;
	int				*key_len;

	fd = open(filename, O_RDONLY);
	key_len = (int *)malloc(sizeof(int) * file_line_len(filename));
	if (key_len == NULL || fd < 0)
		return (-1);
	input_key_len(filename, key_len);
	i = 0;
	while (i < file_line_len(filename))
	{
		key[i] = line_read_key(key_len, &i, fd);
		if (key[i] < 0)
		{
			free(key_len);
			close(fd);
			return (-1);
		}
		i += 1;
	}
	free(key_len);
	close(fd);
	return (0);
}

unsigned char	*line_read_value(int *value_len, int *i, int fd)
{
	unsigned char	*value_str;
	unsigned char	*result;

	value_str = (unsigned char *)malloc(sizeof(char) * (value_len[*i] + 1));
	if (value_str == NULL)
		return (0);
	while (read(fd, value_str, 1) && *value_str != ':')
		;
	read(fd, value_str, value_len[*i]);
	value_str[value_len[*i]] = '\0';
	result = ft_atoc(value_str);
	free(value_str);
	return (result);
}

int	input_value(char *filename, unsigned char **value)
{
	int				fd;
	unsigned char	*value_str;
	int				i;
	int				*value_len;

	fd = open(filename, O_RDONLY);
	value_len = (int *)malloc(sizeof(int) * file_line_len(filename));
	if (value_len == NULL || fd < 0)
		return (-1);
	input_value_len(filename, value_len);
	i = 0;
	while (i < file_line_len(filename))
	{
		value_str = line_read_value(value_len, &i, fd);
		if (value_str == NULL)
		{
			free(value_len);
			close(fd);
			return (-1);
		}
		value[i++] = value_str;
	}
	free(value_len);
	close(fd);
	return (0);
}
