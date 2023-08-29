/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:16:52 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*new;
	int		i;
	int		n_int;

	i = 0;
	n_int = (int)n;
	new = (char *)s;
	while (i != n_int)
	{
		new[i] = c;
		i++;
	}
	return ((void *)s);
}

/*
int	main(void)
{
	void *s;
	int c;
	size_t n;
	char str[] = "Hello";
	char *result;

	n = 5;	
	c = 'c';
	s =  str;
	
	result = ft_memset(s, c, n);
	printf("%p", result);
	return (0);
}
*/