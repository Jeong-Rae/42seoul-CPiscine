/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:17:40 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 22:30:00 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++ s1;
		++ s2;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	i;
	int	j;

	size = ft_strlen(tab);
	i = 0;
	while (i + 1 < size)
	{
		j = 0;
		while (j + 1 < size)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j ++;
		}
		i ++;
	}
}
