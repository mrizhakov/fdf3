/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:20:31 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	counter;
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (s1_new[counter] == s2_new[counter]
		&& (counter < (unsigned int)n - 1))
		counter++;
	return ((unsigned char)s1_new[counter] - (unsigned char)s2_new[counter]);
	return (0);
}
/*
int main(void)
{
	char string1[] = "test\200";
	char string2[] = "test\0";
	unsigned int n;
	int result;
	
	n = 6;
	result = ft_memcmp(string1, string2, n);
	printf("%d \n", result);

	printf("%s \n", string1);
	printf("%s \n", string2);
	return (result);
}


int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[counter] == s2[counter]
		&& s1[counter] != '\0'
		&& s2[counter] != '\0'
		&& (counter < n - 1))
		counter++;
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}


*/