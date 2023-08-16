/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwanki <jihwanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:24:20 by yojin             #+#    #+#             */
/*   Updated: 2023/08/06 16:39:02 by jihwanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(unsigned char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned char	*ft_strcat(unsigned char *dest, unsigned char *src)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (dest[len])
		len++;
	while (src[index])
	{
		dest[len + index] = src[index];
		index++;
	}
	dest[len + index] = '\0';
	return (dest);
}

int	cal_result_len(int size, unsigned char **strs, unsigned char *sep)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

unsigned char	*ft_strjoin(int size, unsigned char **strs, unsigned char *sep)
{
	unsigned char	*result;
	int				i;
	int				result_len;

	if (size == 0)
	{
		result = (unsigned char *)malloc(sizeof(unsigned char));
		*result = '\0';
		return (result);
	}
	i = 0;
	result_len = cal_result_len(size, strs, sep);
	result = (unsigned char *)malloc(sizeof(unsigned char) * (result_len + 1));
	*result = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
