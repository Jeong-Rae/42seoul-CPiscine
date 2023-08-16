/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrki <jeongrki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:22:54 by jeongrki          #+#    #+#             */
/*   Updated: 2023/08/10 12:25:32 by jeongrki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_node
{
	int		n;
	int		m;
	int		max_x;
	int		max_y;
	int		max_length;
	char	empty;
	char	obstacle;
	char	full;
}	t_node;
int		std_input_case(int fd);
int		input_maps_case(char *filename);
int		input_2(int fd, t_node *board_data, char ***board);
int		input_3(char **board, int fd, t_node *board_data);
void	run_bsq(char **board, t_node *board_data);
int		set_dp(char **board, t_node *node, int **dp);
int		is_vaild_node(char **board, int i, int j, t_node *node);
void	update_max_node(t_node *node, int value, int i, int j);
void	write_squre(char **board, t_node *node);
int		get_board_info(int fd, t_node *board_data);
int		get_board_first_line(char **board, int fd, t_node *board_data);
int		get_board_another_line(char **board, int fd, t_node *board_data);
char	**set_board(t_node *node);
void	print_board(char **board, t_node *node);
void	free_board(char **board, t_node *board_data);
void	set_init_data(t_node *board_data);
int		**make_dp_arr(t_node *node);
void	free_dp_arr(int **dp, t_node *node);
char	*ft_realloc(char *ptr, unsigned int size);
char	**allocate_file_name(int argc, char *argv[]);
int		dp_min(int **dp, int i, int j);
int		get_min(int v1, int v2, int v3);
int		is_printable(char ch);
int		is_valid_charset(t_node *data);
int		ft_strlen(char *str);
char	*ft_strdup(char *src, int size);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
