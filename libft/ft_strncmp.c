/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:45:43 by mrizakov          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:51 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

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
/*
int main(void)
{
	char string1[] = "test\200";
	char string2[] = "test\0";
	unsigned int n;
	int result;
	
	n = 6;
	result = ft_strncmp(string1, string2, n);
	printf("%d \n", result);

	printf("%s \n", string1);
	printf("%s \n", string2);
	return (result);
}
*/