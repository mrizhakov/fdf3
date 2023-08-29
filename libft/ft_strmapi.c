/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 22:00:32 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*
size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		printf("%c \n", str[counter]);
		counter++;
	}
	return (counter);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_new;
	unsigned int	i;

	i = 0;
	if (!s || f == NULL)
		return (NULL);
	s_new = malloc(sizeof(char) * ((int)ft_strlen(s) + 1));
	if (!s_new)
		return (NULL);
	while (s[i])
	{
		s_new[i] = f(i, s[i]);
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
/*
char my_func(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}



int main(void)
{
    char    s[] = "LoReM iPsUm";
    
    printf("{%s} \n", ft_strmapi(s, my_func));
    return (0);
}
*/