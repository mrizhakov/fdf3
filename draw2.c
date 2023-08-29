/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'fdf_utils2.c'                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-07-18 15:55:07 by lbaron            :+:    #+#             */
/*   Updated: 2023-07-18 15:55:07 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	intialize_variables_2(t_main *v)
{
	v->z_off = 1;
	v->rw_st = 0;
	v->cl_st = 0;
	v->rw_st = 0;
	v->cl_st = 0;
	v->pr_rw_st = 0;
	v->pr_cl_st = 0;
	v->prev_x = 0;
	v->prev_y = 0;
	v->old_x = 0;
	v->old_y = 0;
	v->new_x = 0;
	v->new_y = 0;
}

void	draw_colums(t_main *v)
{
	while (v->rw_st < v->rw)
	{
		v->cl_st = 0;
		v->pr_cl_st = v->cl_st;
		while (v->cl_st < v->cl)
		{
			v->old_x = conv_x(v->pr_cl_st * v->off, v->rw_st * 
					v->off) + v->x_screen_off;
			v->old_y = conv_y(v->pr_cl_st * v->off, v->rw_st * v->off, -v->mat
				[v->rw_st][v->pr_cl_st] * v->z_off) + v->y_screen_off;
			v->new_x = conv_x(v->cl_st * v->off, v->rw_st * 
					v->off) + v->x_screen_off;
			v->new_y = conv_y(v->cl_st * v->off, v->rw_st * v->off, -v->mat
				[v->rw_st][v->cl_st] * v->z_off) + v->y_screen_off;
			v->dx = abs(v->new_x - v->old_x);
			v->dy = -abs(v->new_y - v->old_y);
			ft_put_line(v);
			v->pr_cl_st = v->cl_st;
			v->cl_st++;
		}
		v->rw_st++;
	}
}

void	draw_rows(t_main *v)
{
	while (v->cl_st < v->cl)
	{
		v->rw_st = 0;
		v->pr_rw_st = v->rw_st;
		while (v->rw_st < v->rw)
		{
			v->old_x = conv_x(v->cl_st * v->off, v->pr_rw_st * 
					v->off) + v->x_screen_off;
			v->old_y = conv_y(v->cl_st * v->off, v->pr_rw_st * v->off, -v->mat
				[v->pr_rw_st][v->cl_st] * v->z_off) + v->y_screen_off;
			v->new_x = conv_x(v->cl_st * v->off, v->rw_st * 
					v->off) + v->x_screen_off;
			v->new_y = conv_y(v->cl_st * v->off, v->rw_st * v->off, -v->mat
				[v->rw_st][v->cl_st] * v->z_off) + v->y_screen_off;
			v->dx = abs(v->new_x - v->old_x);
			v->dy = -abs(v->new_y - v->old_y);
			ft_put_line(v);
			v->pr_rw_st = v->rw_st;
			v->rw_st++;
		}
		v->cl_st++;
	}
}

void	resize_grid_size(t_main *v)
{
	if (v->rw < 10 && v->cl < 10)
		v->off = (int32_t)40;
	else if (v->rw < 20 && v->cl < 20)
		v->off = (int32_t)25;
	else if (v->rw < 50 && v->cl < 50)
		v->off = (int32_t)12;
	else if (v->rw < 100 && v->cl < 100)
		v->off = (int32_t)10;
	else if (v->rw < 250 && v->cl < 250)
		v->off = (int32_t)4;
}

void	set_screen_offset(t_main *v)
{
	if (v->rw <= 10 && v->cl <= 10)
	{
		v->x_screen_off = 350;
		v->y_screen_off = 0;
	}
	else if (v->rw <= 20 && v->cl <= 20)
	{
		v->x_screen_off = 300;
		v->y_screen_off = 50;
	}
	else if (v->rw < 50 && v->cl < 50)
	{
		v->x_screen_off = 300;
		v->y_screen_off = 50;
	}
	else if (v->rw <= 100 && v->cl <= 100)
	{
		v->x_screen_off = 300;
		v->y_screen_off = 50;
	}
	else if (v->rw < 250 && v->cl < 250)
	{
		v->x_screen_off = 450;
		v->y_screen_off = 50;
	}
}
