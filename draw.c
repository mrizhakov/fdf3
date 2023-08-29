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

void	ft_put_line(t_main *v)
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

int32_t	conv_x(int32_t x, int32_t y)
{
	return ((x - y) * cos(0.523599));
}

int32_t	conv_y(int32_t x, int32_t y, int32_t z)
{
	return (z + (x + y) * sin(0.523599));
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	intialize_variables(t_main *v)
{
	v->rw = 0;
	v->cl = 0;
	v->color = 0xFF00FFFF;
}
