/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:45:43 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:47:11 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

/*
size_t	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int 			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	
	unsigned int	counter;
	unsigned char 	*s1_new;
	unsigned char 	*s2_new;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;

	counter = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1_new[counter] == s2_new[counter]
		&& (counter < (unsigned int)n - 1))
		counter++;
	return ((unsigned char)s1_new[counter] - (unsigned char)s2_new[counter]);
	
	return (0);
}

*/
char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	unsigned int	big_i;
	unsigned int	little_i;

	big_i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[big_i] && big_i < len)
	{
		little_i = 0;
		if (big[big_i] == little[little_i])
		{
			while (big_i + little_i < len
				&& big[big_i + little_i] == little[little_i])
			{
				little_i++;
				if (!little[little_i])
					return ((char *)&big[big_i]);
			}
		}
		big_i++;
	}
	return (0);
}
/*
int main(void)
{
	char * empty = (char*)"";

	//const char *big[] = "(char*)""";
	//const char little[] = "coucou";
	unsigned int n;
	char *result;
	//char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	
	n = 15;
	result = ft_strnstr(empty, needle, -1);
	printf("%s \n", result);
	printf("Length of little is %zu", ft_strlen((char *)needle));

	return (0);
}
*/