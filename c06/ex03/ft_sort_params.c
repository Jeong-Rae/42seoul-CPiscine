/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:45:59 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/27 15:13:24 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
			++j;
		}
		++i;
	}
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
