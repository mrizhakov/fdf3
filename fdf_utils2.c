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

//static void	matrix_loop(t_strm *v, int *cl)
void	matrix_loop(t_main *v)

{
	v->split2 = ft_split(v->split[v->i], ' ');
	v->cl = 0;
	while (v->split2[v->cl])
		v->cl++;
	v->mat[v->i] = (int *)malloc(v->cl * sizeof(int));
	v->j = 0;
	while (v->split2[v->j])
	{
		v->mat[v->i][v->j] = ft_atoi(v->split2[v->j]);
		v->j++;
	}
	free_split(v->split2);
	v->i++;
}

void	str_to_matrix(t_main *v)
{
	v->i = 0;
	v->split = ft_split(v->buf, '\n');
	v->rw = 0;
	while (v->buf[v->i])
	{
		if (v->buf[v->i] == '\n')
			v->rw = v->rw + 1;
		v->i++;
	}
	v->mat = (int **)malloc((v->rw) * sizeof(int *));
	v->i = 0;
	while (v->split[v->i])
	{
		matrix_loop(v);
	}
	free_split(v->split);
}

char	*retrieve_buf(const char *arg1)
{
	size_t	rd;
	int		fd;
	char	*buf;
	char	*path;

	buf = (char *)malloc(10000000);
	path = "./maps/";
	path = ft_strjoin(path, arg1);
	fd = open(path, O_RDONLY);
	rd = read(fd, buf, 10000000);
	if (rd == (size_t)-1)
	{
		write(2, "error: invalid map\n", 20);
		exit(0);
	}
	buf[rd] = '\0';
	free(path);
	close(fd);
	return (buf);
}
