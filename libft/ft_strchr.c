/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:59:24 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:21:56 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((char *) NULL);
}

/*
int	main(void)
{
	int c;
	
	
	char s[] = "tripouille";
	c = '\0';
	printf("found %s ", ft_strchr(s, 't' + 256));
	
	
	return (0);
}
*/