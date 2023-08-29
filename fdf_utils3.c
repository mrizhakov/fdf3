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

void	resize_image(t_main *v)
{
	resize_grid_size(v);
	set_screen_offset(v);
}

void	ft_put_2d_matrix(void *param)
{
	t_main	*v;

	v = (t_main *)param;
	intialize_variables_2(v);
	resize_image(v);
	draw_colums(v);
	v->rw_st = 0;
	v->cl_st = 0;
	v->pr_cl_st = 0;
	v->pr_rw_st = 0;
	draw_rows(v);
}

void	ft_randomize(void *param)
{
	ft_put_2d_matrix(param);
}
