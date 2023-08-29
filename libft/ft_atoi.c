/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:34 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:46:46 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	unsigned int	str_c;
	int				result;
	int				positive;

	str_c = 0;
	positive = 1;
	result = 0;
	while (str[str_c] == 32 || (str[str_c] >= 9
			&& str[str_c] <= 13))
		str_c++;
	if (str[str_c] == 45)
	{
		positive = -1;
		str_c++;
	}
	else if (str[str_c] == 43)
		str_c++;
	while (str[str_c] >= 48 && str[str_c] <= 57)
	{
		result = result * 10 + str[str_c] - '0';
		str++;
	}
	return (result * positive);
}
/*
int main(void)
{
	char string1[50] = "-4886";

	printf("%d", ft_atoi(string1));
	return (0);
}
*/