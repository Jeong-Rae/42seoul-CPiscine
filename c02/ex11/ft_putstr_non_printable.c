/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:30:30 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/23 14:36:11 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char ch)
{
	if (32 <= ch && ch <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	char			*hex;
	unsigned char	*uc_str;

	uc_str = (unsigned char *)str;
	hex = "0123456789abcdef";
	idx = 0;
	while (uc_str[idx])
	{
		if (ft_is_printable(uc_str[idx]))
			ft_putchar(uc_str[idx]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[uc_str[idx] / 16]);
			ft_putchar(hex[uc_str[idx] % 16]);
		}
		++idx;
	}
}
