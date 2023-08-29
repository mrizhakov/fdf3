/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:15:31 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					n_new;

	d = dest;
	s = src;
	n_new = (int)n - 1;
	if (dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		while (n_new != -1)
		{
			d[n_new] = s[n_new];
			n_new--;
		}
	}
	return (dest);
}

/*
int    main(void)
{
    char    src[] = "lorem ipsum dolor sit amet";
    char    *dest;

    size_t    n;
    void    *return_value;
    
    dest = src + 1;
    n = 8;
    return_value = ft_memmove(dest, src, n);
    
    printf("%s", (char *)return_value);
    return (0);
}
*/