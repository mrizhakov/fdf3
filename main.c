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

#define WIDTH 1200
#define HEIGHT 1200

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



void ft_put_line(t_main *v, int32_t x0, int32_t y0, int32_t x1, int32_t y1, long color)
{
	//printf("Color is %ld", v->color);

    int32_t dx = abs(x1 - x0);
    int32_t dy = -abs(y1 - y0);
    int32_t sx, sy;

    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }
    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }
    int32_t err = dx + dy, e2;
    while(1)
    {
        if (y0 >= 0 && y0 < HEIGHT && x0 >= 0 && x0 < WIDTH)
            ft_put_pixel(x0, y0, v->color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
			x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

//void ft_put_line_any(int32_t x, int32_t y, int32_t x_end, int32_t y_end, long color)
//{
//	if(x_end > x && y_end > y)
//		ft_put_line(x_end, y_end, x, y, color);
//	else
//		ft_put_line(x, y, x_end, y_end, color);
//}

int32_t conv_x(int32_t x, int32_t y, int32_t z)
{

    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

	float theta = 45.0f * (3.14159265358979323846f / 180.0f);
	float phi = 35.264f * (3.14159265358979323846f / 180.0f);

	 float x_iso = x * cos(phi) + y * cos(theta) * sin(phi);
	float y_iso = y * sin(theta);

	float angle = 45.0f * (3.14159265358979323846f / 180.0f);
	float temp_x = x_iso;

	return ((dx - dy) * cos(0.523599));

}

int32_t conv_y(int32_t x, int32_t y, int32_t z)
{

    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;


	float theta = 45.0f * (3.14159265358979323846f / 180.0f);
	float phi = 35.264f * (3.14159265358979323846f / 180.0f);

	float x_iso = x * cos(phi) + y * cos(theta) * sin(phi);
	float y_iso = y * sin(theta);

	float angle = 45.0f * (3.14159265358979323846f / 180.0f);
	float temp_x = x_iso;

	return (dz + (dx + dy) * sin(0.523599));
}

void intialize_variables_2(t_main *v)
{
	v->offset = 20;
	v->z_offset = 1;

	v->row_start = 0;
	v->col_start = 0;
	v->x_screen_offset = 600;
	v->y_screen_offset = 150;


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
			v->old_x = conv_x(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset);
			v->old_y = conv_y(v->prev_col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->prev_col_start] * v->z_offset);
			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);

			ft_put_line(v, v->old_x + v->x_screen_offset,
						v->old_y + v->y_screen_offset,
						v->new_x + v->x_screen_offset,
						v->new_y + v->y_screen_offset,
						v->color);

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
			v->old_x = conv_x(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset);
			v->old_y = conv_y(v->col_start * v->offset, v->prev_row_start * v->offset, -v->matrix[v->prev_row_start][v->col_start] * v->z_offset);
			v->new_x = conv_x(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
			v->new_y = conv_y(v->col_start * v->offset, v->row_start * v->offset, -v->matrix[v->row_start][v->col_start] * v->z_offset);
			ft_put_line(v, v->old_x + v->x_screen_offset,
						v->old_y + v->y_screen_offset,
						v->new_x + v->x_screen_offset,
						v->new_y + v->y_screen_offset,
						v->color);
//			ft_put_line(v->old_x + v->x_screen_offset,
//						v->old_y + v->y_screen_offset,
//						v->new_x + v->x_screen_offset,
//						v->new_y + v->y_screen_offset,
//						v->color);
			v->prev_row_start = v->row_start;
			v->row_start++;
		}
		v->col_start++;
	}
}




void	ft_put_2d_matrix(void *param)
{

	t_main *v = (t_main *)param;
	intialize_variables_2(v);

	draw_colums(v);

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
	int32_t x = 0;
	int32_t y = 0;
	t_main *v = param;


	int32_t x_end = 256;
	int32_t y_end = 256;


	ft_put_2d_matrix(param);
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

//test

int32_t	init_mlx(mlx_t **mlx, t_main *v)
{
	if (!(*mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
//    if (!(image = mlx_new_image(*mlx, 512, 512)))

        if (!(image = mlx_new_image(*mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	mlx_loop_hook(*mlx, ft_randomize, v);

    mlx_loop_hook(*mlx, ft_hook, *mlx);
    printf("Randomize running now\n");

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
	mlx_t	*mlx;
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

    if (init_mlx(&mlx, &v) != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
    printf("Init MLX running now\n");
    mlx_loop(mlx);
    printf("MLX loop running now\n");
    print_matrix(v.matrix, &v.row, &v.col);
    mlx_terminate(mlx);
	free_matrix(v.matrix, &v.row);
    printf("Freeing matrix now\n");
    free(v.buf);
	return (EXIT_SUCCESS);
}