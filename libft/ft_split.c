/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 18:30:15 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char	**ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
	return (NULL);
}

int	ft_word_count(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

int	ft_size_word(const char *s, char c, int i)
{
	int	word_size;

	word_size = 0;
	while (s[i] != c && s[i])
	{
		word_size++;
		i++;
	}
	return (word_size);
}

char	**ft_split(char const *s, char c)
{
	char			**array;	
	unsigned int	word_count;
	unsigned int	i;
	unsigned int	len;
	unsigned int	y;

	word_count = ft_word_count(s, c);
	y = -1;
	i = 0;
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (++y < word_count)
	{
		while (s[i] == c)
			i++;
		len = ft_size_word(s, c, i);
		array[y] = ft_substr(s, i, len);
		if (!array[y])
			ft_free(array, y);
		i = i + len;
	}
	array[y] = 0;
	return (array);
}

/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}
	

int main(void)
{
	
	//char const	*s = "      split       this for   me  !       ";
	//char		c = ' ';
	//char **array;

	int i;
	char	**tabstr;

	i = 0;

	//array = ft_split(s, c);	

//ft_split("hello!", ' ');

	if (!(tabstr = ft_split("hello!", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i])
			{
				printf("%s\n", tabstr[i]);
				//ft_print_result(tabstr[i]);
				//printf("%d", i);
				//write(1, "\n", 1);
				i++;
			}
			printf("%s\n", tabstr[i]);
		}

	return (0);
}
*/