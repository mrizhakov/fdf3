/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:45:43 by mrizakov          #+#    #+#             */
/*   Updated: 2022/12/10 15:16:30 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

/*
int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
*/

unsigned int	ft_strlcat(char *dest, char *str, unsigned int size)
{
	unsigned int	str_counter;
	unsigned int	dest_counter;
	unsigned int	str_size;
	unsigned int	dest_size;

	str_counter = 0;
	dest_counter = 0;
	while (dest[dest_counter] != '\0')
	{
		dest_counter++;
	}
	dest_size = dest_counter;
	str_size = ft_strlen(str);
	if (size == 0 || size <= dest_size)
	{
		return (str_size + size);
	}
	while (str[str_counter] != '\0' && str_counter < size - dest_size - 1)
	{
		dest[dest_counter] = str[str_counter];
		str_counter++;
		dest_counter++;
	}
	dest[dest_counter] = '\0';
	return (dest_size + str_size);
}

/*
int main(void)
{
	char string1[] = "12345678901234567890";
	char string2[] = " me";
	unsigned int size = 7;
	int result;
	
	result = ft_strlcat(string1, string2, size);
	printf("%d", result); 

	printf("%s", string1);
	printf("%s", string2);

	return (result);
}
*/
