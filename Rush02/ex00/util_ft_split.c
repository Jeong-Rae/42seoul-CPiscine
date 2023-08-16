/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwanki <jihwanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:47:58 by yojin             #+#    #+#             */
/*   Updated: 2023/08/06 16:39:18 by jihwanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(unsigned char *str);

int	is_in_charset(unsigned char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_word_count(unsigned char *str, char *charset)
{
	int	count;

	count = 0;
	if (!is_in_charset(*str, charset))
		count++;
	while (*(str + 1) != '\0')
	{
		if (is_in_charset(*str, charset) && !is_in_charset(*(str + 1), charset))
			count++;
		str++;
	}
	return (count);
}

unsigned char	*ft_strdup(unsigned char *src, char *charset)
{
	int				len;
	int				i;
	unsigned char	*dup;

	len = 0;
	i = 0;
	while (src[len] && !is_in_charset(src[len], charset))
		len++;
	dup = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

unsigned char	**ft_split(unsigned char *str, char *charset)
{
	unsigned char	**strs;
	int				i;
	int				words;

	words = get_word_count(str, charset);
	strs = (unsigned char **)malloc(sizeof(unsigned char *) * (words + 1));
	if (!strs)
		return (0);
	i = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
		{
			str++;
			continue ;
		}
		strs[i] = ft_strdup(str, charset);
		if (!strs[i])
			return (0);
		str += ft_strlen(strs[i]);
		i++;
	}
	strs[words] = 0;
	return (strs);
}
