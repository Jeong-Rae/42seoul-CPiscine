/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:55:21 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/07 15:19:26 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1

int	main(void)
{
	char	buf[BUF_SIZE];
	char	*filename;
	int		fd;
	filename = "test";
	fd = open(filename, O_RDONLY);
	while (read(fd, buf, BUF_SIZE) != 0)
	{
		write(1, buf, BUF_SIZE);
	}
	return (0);
}
