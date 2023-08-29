/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:20:45 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_bzero(void *s, size_t n)
{
	char	*new;
	int		n_int;
	int		i;

	i = 0;
	n_int = (int)n;
	new = (char *)s;
	while (i != n_int)
	{
		new[i] = '\0';
		i++;
	}
	return ((void *)s);
}
/*
int	main(void)
{
	void *s;
	size_t n;
	char str[] = "Hello";
	char *result;

	n = 5;	
	s =  str;
	
	result = ft_bzero(s, n);
	printf("%p", result);
	return (0);
}
*/