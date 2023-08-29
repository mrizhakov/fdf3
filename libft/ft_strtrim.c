/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:28:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

#include<stdio.h>
#include<stdlib.h>

/*
int   ft_strlen(char *str)
{
    int    counter;

    counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return (counter);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
 	unsigned int	new_n;
	char			*char_dest;
	char			*char_src;
	unsigned int 	i;

	char_dest = (char *)dest;
	char_src =  (char *)src;
	i = 0;
	new_n = (unsigned int)n;
	
	if (!dest && !src)
	{
		return (NULL);
	}
	
	while (i < new_n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (char_dest); 

}

char	*ft_strdup(const char *s)
{
	char	*s_new;
	int		s_size;
	int		i;

	i = 0;
	s_new = NULL;
	s_size = ft_strlen((char *)s);
	if (!malloc(s_size + 1))
		return (NULL);
	s_new = malloc(s_size + 1);
	
	s_new = ft_memcpy(s_new, s, s_size);
	s_new[s_size] = '\0';
	return (s_new);
}
*/

int	ft_word_letter_compare(char const letter, char const *set)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != '\0')
	{
		if (letter == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copy_correct_str(int start, int end, char const *s1)
{
	char			*new_str;
	unsigned int	new_str_i;

	new_str = NULL;
	new_str_i = 0;
	if (start > end)
		return (ft_strdup(""));
	new_str = malloc(end - start + 2);
	if (!(new_str))
		return ((void *) NULL);
	while (start <= end)
	{
		new_str[new_str_i] = s1[start];
		start++;
		new_str_i++;
	}
	new_str[new_str_i] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s1_i;
	unsigned int	s1_len;
	unsigned int	start;
	unsigned int	end;

	if (s1 == NULL || s1[0] == '\0')
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup((char *)s1));
	s1_len = ft_strlen((char *)s1) - 1;
	s1_i = 0;
	while (ft_word_letter_compare(s1[s1_i], set) == 1 && s1[s1_i] != '\0')
	{
		s1_i++;
	}
	start = s1_i;
	while (ft_word_letter_compare(s1[s1_len], set) == 1 && s1_len != 0)
	{
		s1_len--;
	}
	end = s1_len;
	return (ft_copy_correct_str(start, end, s1));
}
/*
int main(void)
{
    char    s1[] = "";
    char    set[] = "";

    printf("{%s} \n", ft_strtrim(s1, set));
    return (0);
}
*/