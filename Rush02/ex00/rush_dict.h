/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_dict.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:31:43 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/06 17:12:56 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_DICT_H
# define RUSH_DICT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int				file_line_len(char *filename);
void			input_key_len(char *filename, int *key_len);
void			input_value_len(char *filename, int *value_len);
long long		ft_atoi(char *str);
unsigned char	*ft_atoc(unsigned char *str);
int				input_key(char *filename, long long *key);
int				input_value(char *filename, unsigned char **value);
unsigned char	*ft_strjoin(int size, unsigned char **strs, char *sep);
unsigned char	**ft_split(unsigned char *str, char *charset);
long long		*malloc_input_key(char *filename);
unsigned char	**malloc_input_value(char *filename);

#endif
