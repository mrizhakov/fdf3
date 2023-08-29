/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/07 21:54:26 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<stdlib.h>

int	ft_count_nbr(int n)
{
	int	sign;
	int	len;

	len = 1;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		len++;
		n = n * sign;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	if (n == -2147483648)
	{
		len = 11;
	}
	return (len);
}

int	ft_decimal_place(int value, int power)
{
	while (power != 0)
	{
		value = value * 10;
		power--;
	}
	return (value);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count_nbr(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		str[0] = 48;
	while (n > 0)
	{
		str[len] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

/*
int main(void)
{
    int		i;
	int 	number;
	char 	*result;
	int		size;

	i = 0;
	number = -2147483648;
	size = sizeof(number);
	result = ft_itoa(number);
	while (result[i] != '\0')
	{
		printf("{%s} \n", result);
		i++;
	}
    return (0);
}
*/