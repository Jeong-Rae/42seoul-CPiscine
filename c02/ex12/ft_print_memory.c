/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:57:41 by jeongrki          #+#    #+#             */
/*   Updated: 2023/07/26 12:10:22 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	print_memory_address(unsigned long long int n)
{
	char	hex_address[18];
	char	*hex_dights;
	int		idx;

	hex_dights = "0123456789abcdef";
	hex_address[16] = ':';
	hex_address[17] = ' ';
	idx = 16;
	while (idx--)
	{
		hex_address[idx] = hex_dights[n % 16];
		n /= 16;
	}
	write(1, hex_address, 18);
}

void	print_hexcode(unsigned char ch, int idx)
{
	char	*hex_dights;

	hex_dights = "0123456789abcdef ";
	write(1, &hex_dights[ch / 16], 1);
	write(1, &hex_dights[ch % 16], 1);
	if (idx % 2)
		write(1, &hex_dights[16], 1);
}

void	print_string(unsigned char ch)
{
	if (32 <= ch && ch <= 126)
		write(1, &ch, 1);
	else
		write(1, ".", 1);
}

void	print_another_line(unsigned char *p, int re_n)
{
	int	idx;

	if (!re_n)
		return ;
	idx = re_n + 1;
	print_memory_address((unsigned long long int)(p));
	while (--idx)
		print_hexcode(p[re_n - idx], re_n - idx);
	if (re_n % 2)
		write(1, "   ", 3);
	idx = (16 - re_n) / 2;
	while (idx--)
		write(1, "     ", 5);
	idx = re_n + 1;
	while (--idx)
		print_string(p[re_n - idx]);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned char	*p;
	int				idx;
	unsigned int	line;

	str = (unsigned char *)addr;
	p = str;
	line = 0;
	while (line < size / 16)
	{
		print_memory_address((unsigned long long int)(p));
		idx = 17;
		while (--idx)
			print_hexcode(p[16 - idx], 16 - idx);
		idx = 17;
		while (--idx)
			print_string(p[16 - idx]);
		write(1, "\n", 1);
		++line;
		p += 16;
	}
	print_another_line(p, size % 16);
	return (addr);
}
