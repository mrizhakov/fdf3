/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:36:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

/*
void	*ft_bzero(void *s, size_t n)
{
	char	*new;
	int n_int;
	int i;

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
*/

void	*ft_calloc(size_t number_elements, size_t element_size)
{
	void	*ptr;

	if (number_elements * element_size > 2147483647)
	{
		return (NULL);
	}
	ptr = malloc (number_elements * element_size);
	if (ptr == 0)
	{
		return (ptr);
	}
	ft_bzero(ptr, number_elements * element_size);
	return (ptr);
}

/*
int main(void)
{
	
	ft_calloc(5, 3);
	
	return (0);
}
*/