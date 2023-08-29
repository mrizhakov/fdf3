/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:38:11 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>

/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

/*
int main(void)
{
    char 	*str = "hello there";;
	int		fd;
	char 	*file_name;
	

	file_name = "text.txt";

	fd = open(file_name, O_RDWR);
	//str = "hello there";
	ft_putstr_fd(str, fd);
    return (0);
}
*/