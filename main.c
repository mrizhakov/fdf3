/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:23:44 by mrizakov          #+#    #+#             */
/*   Updated: 2023/08/07 23:23:44 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(int32_t x, int32_t y, long color)
{
	mlx_put_pixel(g_image, x, y, color);
}

void	ft_put_line_loop(t_main *v)
{
	while (1)
	{
		if (v->old_y >= 0 && v->old_y < HEIGHT 
			&& v->old_x >= 0 && v->old_x < WIDTH)
			ft_put_pixel(v->old_x, v->old_y, v->color);
		if (v->old_x == v->new_x && v->old_y == v->new_y)
			break ;
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

void	ft_hook(void *param)
{
	t_main	*v;

	v = (t_main *) param;
	if (mlx_is_key_down(v->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(v->mlx);
	if (mlx_is_key_down(v->mlx, MLX_KEY_UP))
		g_image->instances[0].y -= 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_DOWN))
		g_image->instances[0].y += 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_LEFT))
		g_image->instances[0].x -= 5;
	if (mlx_is_key_down(v->mlx, MLX_KEY_RIGHT))
		g_image->instances[0].x += 5;
}

//
//void ft_commands(void *param)
//{
//    t_main *v;
//
//    v = (t_main *)param;
//    if (mlx_is_key_down(v->mlx, MLX_KEY_A))
//    {
//       // mlx_delete_image(v->mlx, v->image);
//        v->z_offset += 1;
//    }
//    if (mlx_is_key_down(v->mlx, MLX_KEY_B))
//        image->instances[0].x += 50;
//}

int32_t	init_mlx(mlx_t **mlx, t_main *v)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!(*mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	g_image = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!(g_image))
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, g_image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(*mlx, ft_randomize, v);
	mlx_loop_hook(*mlx, ft_hook, v);
	return (EXIT_SUCCESS);
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_main	v;

	if (argc != 2)
	{
		write(2, "error: you need a valid map name\n", 33);
		return (0);
	}
	intialize_variables(&v);
	v.buf = retrieve_buf(argv[1]);
	str_to_matrix(&v);
	if (init_mlx(&v.mlx, &v) != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	mlx_loop(v.mlx);
	mlx_terminate(v.mlx);
	free_matrix(v.mat, &v.rw);
	free(v.buf);
	return (EXIT_SUCCESS);
}
