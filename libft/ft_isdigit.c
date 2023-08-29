/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:56:29 by mrizakov          #+#    #+#             */
/*   Updated: 2022/12/06 19:35:17 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
	}
	else
	{
		return (0);
	}
	return (1);
}
/*
int main(void)
{
	int c = 1;

	printf("%d", ft_isdigit(c));
	return (0);
}
*/