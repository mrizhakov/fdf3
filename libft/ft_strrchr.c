/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:59:24 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:23:48 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include"libft.h"

/*
int    ft_strlen(char *str)
{
    int    counter;

    counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return (counter);
}
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_new;

	i = ft_strlen((char *)s);
	s_new = (char *)s;
	while ((i != 0) && (s_new[i] != (char)c))
		i--;
	if (s_new[i] == (char)c)
		return (s_new + i);
	return ((char *) NULL);
}

/*
int    main(void)
{
    int c;
    
    
    char str[8] = "bonjour";
    c = 'o';
    
    printf("%s ", ft_strrchr(str, c));
    return (0);
}
*/