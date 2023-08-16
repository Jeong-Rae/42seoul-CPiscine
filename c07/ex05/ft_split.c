/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:20:15 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/03 19:28:50 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char ch, char *charset)
{
	while (*charset)
	{
		if (ch == *charset)
			return (1);
		++ charset;
	}
	return (0);
}

int	get_words_count(char *str, char *charset)
{
	int		words_count;
	int		in_word;

	in_word = 0;
	words_count = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
			in_word = 0;
		else if (!in_word && !is_separator(*str, charset))
		{
			in_word = 1;
			words_count ++;
		}
		++ str;
	}
	return (words_count);
}

void	set_index_table(char *str, char *charset, int *index_table)
{
	int		in_word;
	int		index;
	int		count;

	index = 0;
	in_word = 0;
	count = 0;
	while (str[index])
	{
		if (in_word && is_separator(str[index], charset))
		{
			in_word = 0;
			count ++;
		}
		else if (!in_word && !is_separator(str[index], charset))
		{
			index_table[count] = index;
			in_word = 1;
		}
		index ++;
	}
	if (in_word)
		count ++;
	index_table[count] = index;
}

void	set_word(char *str, char *charset, char *part, int index)
{
	int	i;

	i = 0;
	while (!is_separator(str[index + i], charset) && str[index + i])
	{
		part[i] = str[index + i];
		i ++;
	}
	part[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**answer;
	int		*index_table;
	int		words_count;
	int		i;

	words_count = get_words_count(str, charset);
	answer = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!answer)
		return (0);
	answer[words_count] = 0;
	index_table = (int *)malloc((words_count + 1) * sizeof(int));
	if (!index_table)
		return (0);
	set_index_table(str, charset, index_table);
	i = 0;
	while (i < words_count)
	{
		answer[i] = (char *)malloc(index_table[i + 1] - index_table[i] + 1);
		set_word(str, charset, answer[i], index_table[i]);
		i ++;
	}
	return (answer);
}
