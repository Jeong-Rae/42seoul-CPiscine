/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:21:08 by jihwanki          #+#    #+#             */
/*   Updated: 2023/08/06 18:17:15 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_list.h"
#include "rush_out.h"
#include "rush_dict.h"

void	ft_free(long long *key, unsigned char **value)
{
	unsigned char	**free_add;

	free_add = value;
	if (key)
		free(key);
	if (value)
	{
		while (*free_add)
			free(*free_add++);
		free(value);
	}
}

int	check_command(char *str, t_ull *target)
{
	char	*pc;
	t_ull	result;

	pc = str;
	result = 0;
	if (*pc == '+' && pc[1] >= '0' && pc[1] <= '9')
		pc ++;
	else if (!*pc)
		return (0);
	while (*pc)
	{
		if (*pc < '0' || *pc > '9')
			return (0);
		result = 10 * result + *pc - '0';
		if (result >= 1000000000000)
		{
			write(1, "Dict Error\n", 11);
			return (-1);
		}
		pc ++;
	}
	*target = result;
	return (1);
}

int	convert(char *filename, t_ull target_key)
{
	long long		*key;
	unsigned char	**value;
	t_list			*header;

	key = malloc_input_key(filename);
	if (!key)
		return (-1);
	value = malloc_input_value(filename);
	if (!value)
	{
		ft_free(key, value);
		return (-1);
	}
	header = init_list(key, value);
	if (!header)
	{
		free_list(header);
		ft_free(key, value);
		return (-1);
	}
	translate(header, target_key);
	free_list(header);
	ft_free(key, value);
	return (0);
}

int	is_invalid_filename(char *filename)
{
	int	n;

	n = open(filename, O_RDONLY);
	close(n);
	if (n < 0)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	char			*filename;
	t_ull			target_key;
	int				flag;

	flag = check_command(argv[argc - 1], &target_key);
	if (argc == 2 && flag > 0)
		filename = "numbers.dict";
	else if (argc == 3 && flag > 0)
	{
		filename = argv[1];
		if (is_invalid_filename(filename))
			return (0);
	}
	else
	{
		if (flag != -1)
			write(1, "Error\n", 6);
		return (0);
	}
	if (convert(filename, target_key) == -1)
		return (-1);
	return (0);
}
