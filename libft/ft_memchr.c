/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:43:13 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*new;

	new = (unsigned char *)s;
	while (n-- != 0)
	{
		if ((unsigned char)c == *new++)
			return ((void *)(new - 1));
	}
	return (NULL);
}

/*
int	main(void)
{
	
	//void *s;
	size_t n;
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char c;
	char *result;
	//char *result1;

	n = 0;	
	//s =  str;
	c = 0;
	result = ft_memchr(s, c, n);
	//result1 = ft_memchr(s, c, n);
	printf("%s \n", result);
	//printf("%s \n", result1);
	
	
	//int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//printf("%s", (char *)ft_memchr(tab, -1, 7));
	return (0);
}
*/