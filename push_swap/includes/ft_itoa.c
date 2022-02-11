/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:50:12 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/08 13:21:33 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_itoa(long long n)
{
	char	*str;
	int		len;
	int		sign;

	sign = minus(n);
	len = intsize(n) + sign;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	str[--len] = 0;
	if (n < 0)
		n = -n;
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
