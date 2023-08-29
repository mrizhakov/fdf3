/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:16:08 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

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


void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned int	new_n;
	char			*char_dest;
	char			*char_src;
	unsigned int 	i;

	char_dest = (char *)dest;
	char_src =  (char *)src;
	i = 0;
	new_n = (unsigned int)n;

	if (dest == NULL)
		return NULL;
	
	while (i < new_n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (char_dest);
}
*/
char	*ft_strdup(const char *s)
{
	char	*s_new;
	size_t	s_size;

	s_size = ft_strlen(s) + 1;
	s_new = (char *)malloc(sizeof(*s_new) * s_size);
	if (!s_new)
		return (NULL);
	return ((char *)ft_memcpy(s_new, s, s_size));
}
/*
int	main(void)
{
	char string1[] = "test200";
	
	//char result[100] = 
	ft_strdup(string1);
	//printf("%s \n", result);

	return (0);
}

*/