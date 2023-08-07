/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'main.c'                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-07-18 15:24:19 by lbaron            :+:    #+#             */
/*   Updated: 2023-07-18 15:24:19 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 1280
#define HEIGHT 1024

static	mlx_image_t	*image;

// -----------------------------------------------------------------------------

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_put_pixel(int32_t x, int32_t y, long color)
{
	mlx_put_pixel(image, x, y, color);
}

void ft_put_line_loop(t_main *v)
{
    while(1)
    {
        if (v->old_y >= 0 && v->old_y < HEIGHT && v->old_x >= 0 && v->old_x < WIDTH)
            ft_put_pixel(v->old_x, v->old_y, v->color);
        if (v->old_x == v->new_x && v->old_y == v->new_y)
            break;
        v->e2 = 2 * v->err;
        if (v->e2 >= v->dy)
        {
            v->err += v->dy;
            v->old_x += v->sx;
        }
        if (v->e2 <= v->dx)
        {
            v->err += v->dx;
            v->old_y += v->sy;
        }
    }
}


void ft_put_line(t_main *v)
{
    if (v->old_x < v->new_x)
        v->sx = 1;
    else
        v->sx = -1;
    if (v->old_y < v->new_y)
        v->sy = 1;
    else
        v->sy = -1;
    v->err = v->dx + v->dy;
    ft_put_line_loop(v);
}

int32_t conv_x(int32_t x, int32_t y, int32_t z)
{
	return ((x - y) * cos(0.523599));
}

int32_t conv_y(int32_t x, int32_t y, int32_t z)
{
	return (z + (x + y) * sin(0.523599));
}

void intialize_variables_2(t_main *v)
{
	//v->offset = 20;
	v->z_offset = 1;
	v->row_start = 0;
	v->col_start = 0;
//	v->x_screen_offset = 600;
//	v->y_screen_offset = 150;
	v->row_start = 0;
	v->col_start = 0;
	v->prev_row_start = 0;
	v->prev_col_start = 0;
	v->prev_x = 0;
	v->prev_y = 0;
	v->old_x = 0;
	v->old_y = 0;
	v->new_x = 0;
	v->new_y = 0;
}


void	draw_colums(t_main *v)
{
	while (v->row_start < v->row)
	{
		v->col_start = 0;
		v->prev_col_start = v->col_start;
		while (v->col_start < v->col)
		{
			v->old_x = conv_x(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset) + v->x_screen_offset;
			v->old_y = conv_y(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset) + v->y_screen_offset;
			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset) + v->x_screen_offset;
			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset) + v->y_screen_offset;
            v->dx = abs(v->new_x - v->old_x);
            v->dy = -abs(v->new_y - v->old_y);
			ft_put_line(v);
			v->prev_col_start = v->col_start;
			v->col_start++;
		}
		v->row_start++;
	}
}

void	draw_rows(t_main *v)
{
	while (v->col_start < v->col)
	{
		v->row_start = 0;
		v->prev_row_start = v->row_start;
		while (v->row_start < v->row)
		{
			v->old_x = conv_x(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset) + v->x_screen_offset;
			v->old_y = conv_y(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset) + v->y_screen_offset;
			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset) + v->x_screen_offset;
			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset) + v->y_screen_offset;
            v->dx = abs(v->new_x - v->old_x);
            v->dy = -abs(v->new_y - v->old_y);
            ft_put_line(v);
			v->prev_row_start = v->row_start;
			v->row_start++;
		}
		v->col_start++;
	}
}

void	resize_grid_size(t_main *v)
{
    if (v->row < 10 && v->col < 10)
        v->offset = (int32_t)40;
    else if (v->row < 20 && v->col < 20)
        v->offset = (int32_t)25;
    else if (v->row < 50 && v->col < 50)
        v->offset = (int32_t)12;
    else if (v->row < 100 && v->col < 100)
        v->offset = (int32_t)10;
    else if (v->row < 250 && v->col < 250)
        v->offset = (int32_t)4;
}

void	set_screen_offset(t_main *v)
{
    if (v->row <= 10 && v->col <= 10) {
        v->x_screen_offset = 350;
        v->y_screen_offset = 0;
    } else if (v->row <= 20 && v->col <= 20) {
        v->x_screen_offset = 300;
        v->y_screen_offset = 50;
    } else if (v->row < 50 && v->col < 50) {
        v->x_screen_offset = 300;
        v->y_screen_offset = 50;
    } else if (v->row <= 100 && v->col <= 100) {
        v->x_screen_offset = 300;
        v->y_screen_offset = 50;
    } else if (v->row < 250 && v->col < 250) {
        v->x_screen_offset = 450;
        v->y_screen_offset = 50;
    }
}



void	resize_image(t_main *v)
{
    resize_grid_size(v);
    set_screen_offset(v);

}


void	ft_put_2d_matrix(void *param)
{

	t_main *v;

    v = (t_main *)param;

	intialize_variables_2(v);
    resize_image(v);
//    v->offset = WIDTH / v->row/2.5;
//   // v->z_offset = v->offset/12; //
//
//    v->x_screen_offset = v->row * v->offset;
//    v->y_screen_offset = v->col/4 * v->offset;


   // v->offset = WIDTH- x_screen/v->row;

//    if (v->row > 30)
//    {
//        v->offset = 6;
//        v->z_offset = 1;
//        v->x_screen_offset = 400;
//        v->y_screen_offset = 50;
//    }

	draw_colums(v);
    printf("Rows are %d\n", v->row);
    printf("Cols are %d\n", v->col);



//	int32_t offset = 20;
//    int32_t z_offset = 1;
//
//    int32_t row_start = 0;
//	int32_t col_start = 0;
//    int32_t x_screen_offset = 600;
//    int32_t y_screen_offset = 150;
//
//
//    row_start = 0;
//    col_start = 0;
//    int32_t prev_row_start = 0;
//    int32_t prev_col_start = 0;
//    int32_t prev_x = 0;
//    int32_t prev_y = 0;
//    int32_t old_x = 0;
//    int32_t old_y = 0;
//    int32_t new_x = 0;
//    int32_t new_y = 0;

//	while (v->row_start < v->row)
//	{
//		v->col_start = 0;
//		v->prev_col_start = v->col_start;
//		while (v->col_start < v->col)
//		{
//			v->old_x = conv_x(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset);
//			v->old_y = conv_y(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset);
//			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
//			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
//
//            ft_put_line(v->old_x + v->x_screen_offset,
//						v->old_y + v->y_screen_offset,
//						v->new_x + v->x_screen_offset,
//						v->new_y + v->y_screen_offset,
//                        v->color);
//
//			v->prev_col_start = v->col_start;
//			v->col_start++;
//		}
//		v->row_start++;
//	}
printf("v->new_x is %d\n", v->new_x);
    printf("v->new_y is %d\n", v->new_y);
    //exit(1);

	v->row_start = 0;
	v->col_start = 0;
	v->prev_col_start = 0;
	v->prev_row_start = 0;
	draw_rows(v);


//
//	while (v->col_start < v->col)
//    {
//		v->row_start = 0;
//		v->prev_row_start = v->row_start;
//        while (v->row_start < v->row)
//        {
//			v->old_x = conv_x(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset);
//			v->old_y = conv_y(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset);
//			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
//			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
//
//            ft_put_line(v->old_x + v->x_screen_offset,
//						v->old_y + v->y_screen_offset,
//						v->new_x + v->x_screen_offset,
//						v->new_y + v->y_screen_offset,
//                        v->color);
//
//			v->prev_row_start = v->row_start;
//			v->row_start++;
//        }
//		v->col_start++;
//    }
}

void	ft_randomize(void *param)
{
	ft_put_2d_matrix(param);
}

void	ft_hook(void *param)
{
	t_main *v;

	v = (t_main *) param;
	if (mlx_is_key_down(v->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(v->mlx);
	if (mlx_is_key_down(v->mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;


}

//test

void ft_commands(void *param)
{
    t_main *v;

    v = (t_main *)param;
    if (mlx_is_key_down(v->mlx, MLX_KEY_A))
    {
       // mlx_delete_image(v->mlx, v->image);
        v->z_offset += 1;
    }
    if (mlx_is_key_down(v->mlx, MLX_KEY_B))
        image->instances[0].x += 50;



}

int32_t	init_mlx(mlx_t **mlx, t_main *v)
{
	if (!(*mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
//    if (!(image = mlx_new_image(*mlx, 512, 512)))
    v->image = mlx_new_image(*mlx, WIDTH, HEIGHT);
        if (!v->image)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, v->image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

    mlx_loop_hook(*mlx, ft_randomize, v);
    mlx_loop_hook(*mlx, ft_commands, v);


    mlx_loop_hook(*mlx, ft_hook, v);

    printf("Randomize running now\n");
    printf("V-zoffset if %d\n", v->z_offset);


    return (EXIT_SUCCESS);
}

void intialize_variables(t_main *v)
{
	v->row = 0;
	v->col = 0;
	v->color = 0xFF00FFFF;
}

int32_t	main(int32_t argc, const char *argv[])
{
	//mlx_t	*mlx;
	t_main	v;
	if (argc != 2)
	{
		write(2, "error: you need a valid map name\n", 33);
		return (0);
	}
//	v.row = 0;
//	v.col = 0;
	intialize_variables(&v);

	v.buf = retrieve_buf(argv[1]);
    //sprintf("Retrieve buf working now\n");

//    v.matrix = str_to_matrix(v.buf, &v.row, &v.col);
//	v.matrix = str_to_matrix(&v);
	str_to_matrix(&v);

	printf("Str to matrix working now\n");

    print_matrix(v.matrix, &v.row, &v.col);
    printf("Print matrix working now\n");

    if (init_mlx(&v.mlx, &v) != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
    printf("Init MLX running now\n");
    mlx_loop(v.mlx);
    printf("MLX loop running now\n");
    print_matrix(v.matrix, &v.row, &v.col);
    mlx_terminate(v.mlx);
	free_matrix(v.matrix, &v.row);
    printf("Freeing matrix now\n");
    free(v.buf);
	return (EXIT_SUCCESS);
}