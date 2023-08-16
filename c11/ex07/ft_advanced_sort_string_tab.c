/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:30:19 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 23:25:04 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_adv_strlen(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

void	ft_adv_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	i;
	int	j;

	size = ft_adv_strlen(tab);
	i = 0;
	while (i + 1 < size)
	{
		j = 0;
		while (j + 1 < size)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_adv_swap(&tab[j], &tab[j + 1]);
			j ++;
		}
		i ++;
	}
}
