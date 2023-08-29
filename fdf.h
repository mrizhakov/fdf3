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
# define WIDTH 1280
# define HEIGHT 1024

static	mlx_image_t	*g_image;

typedef struct s_main
{
	int32_t		rw;
	int32_t		cl;
	long		color;
	char		*buf;
	int			**mat;
	int			i;
	int			j;
	char		**split;
	char		**split2;
	int32_t		off;
	int32_t		z_off;
	int32_t		rw_st;
	int32_t		cl_st;
	int32_t		x_screen_off;
	int32_t		y_screen_off;
	int32_t		pr_rw_st;
	int32_t		pr_cl_st;
	int32_t		prev_x;
	int32_t		prev_y;
	int32_t		old_x;
	int32_t		old_y;
	int32_t		new_x;
	int32_t		new_y;
	int32_t		dx;
	int32_t		dy;
	int32_t		sx;
	int32_t		sy;
	int32_t		err;
	int32_t		e2;
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_main;

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

void		ft_randomize(void *param);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_hook(void *param);
int32_t		init_mlx(mlx_t **mlx, t_main *v);
void		intialize_variables(t_main *v);
void		ft_put_pixel(int32_t x, int32_t y, long color);
void		ft_put_line_loop(t_main *v);
void		ft_put_line(t_main *v);
int32_t		conv_x(int32_t x, int32_t y);
int32_t		conv_y(int32_t x, int32_t y, int32_t z);
void		intialize_variables_2(t_main *v);
void		draw_colums(t_main *v);
void		draw_rows(t_main *v);
void		resize_grid_size(t_main *v);
void		set_screen_offset(t_main *v);
void		print_split(char **split);
void		print_matrix(int **matrix, int *rw, int *cl);
void		free_matrix(int **matrix, int *rw);
void		free_split(char **split);
void	matrix_loop(t_main *v);
void		str_to_matrix(t_main *v);
void		resize_image(t_main *v);
void		ft_put_2d_matrix(void *param);
char		*retrieve_buf(const char *arg1);
void		intialize_variables_2(t_main *v);
void		intialize_variables(t_main *v);
void		draw_colums(t_main *v);
void		draw_rows(t_main *v);

#endif //FDF_H
