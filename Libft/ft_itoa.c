/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:50:12 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/08 15:12:07 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	intsize(int num)
{
	int	i;

	i = 1;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	minus(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	sign = minus(n);
	len = intsize(n) + sign;
	str = (char *)malloc(len);
	str[--len] = 0;
	if (n < 0)
		n = -n;
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		printf("%c__", str[len]);
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
