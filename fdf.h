/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'fdf.h'                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-07-18 15:43:02 by lbaron            :+:    #+#             */
/*   Updated: 2023-07-18 15:43:02 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_main
{
	int32_t 		row;
	int32_t 		col;
	long			color;
	char			*buf;
	int				**matrix;
	int		i;
	int		j;
	char	**split;
	char	**split2;
	int32_t offset;
	int32_t z_offset;

	int32_t row_start;
	int32_t col_start;
	int32_t x_screen_offset;
	int32_t y_screen_offset;



	int32_t prev_row_start;
	int32_t prev_col_start;
	int32_t prev_x;
	int32_t prev_y;
	int32_t old_x;
	int32_t old_y;
	int32_t new_x;
	int32_t new_y;
	//int		**matrix;
}t_main;

typedef struct s_data
{
	int		char_h_size;
	int		int_h_size;
	int		v_size;
	int		**map_ints;
	char	**map_chars;
}t_data;

typedef struct s_strm
{
	int		i;
	int		j;
	char	**split;
	char	**split2;
	int		**matrix;
}t_strm;

//fdf_utils.c

void	print_split(char **split);
void	print_matrix(int **matrix, int *rw, int *cl);
void	free_matrix(int **matrix, int *rw);
void	free_split(char **split);

//fdf_utils2.c

//int		**str_to_matrix(char *buf, int *rw, int *cl);
void str_to_matrix(t_main *v);

char	*retrieve_buf(const char *arg1);
void intialize_variables_2(t_main *v);
void	intialize_variables(t_main *v);
void	draw_colums(t_main *v);
void	draw_rows(t_main *v);




#endif //FDF_H
