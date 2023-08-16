/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:56:44 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/21 21:04:43 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlowcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ('A' <= str[idx] && str[idx] <= 'Z')
			str[idx] += 'a' - 'A';
		++idx;
	}
	return (str);
}

void	tr_cap(char *ch, char prev)
{
	int	flag;

	flag = 0;
	if ((prev < 'A' || prev > 'Z')
		&& (prev < 'a' || prev > 'z')
		&& (prev < '0' || prev > '9'))
		flag = 1;
	if (flag && 'a' <= *ch && *ch <= 'z')
		*ch -= 32;
}

char	*ft_strcapitalize(char *str)
{
	char	prev;
	char	*p;

	p = str;
	strlowcase(p);
	if ('a' <= *p && *p <= 'z')
		*p += 'A' - 'a';
	prev = *p;
	while (*(++p))
	{
		tr_cap(p, prev);
		prev = *p;
	}
	return (str);
}
