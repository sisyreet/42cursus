/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:50:12 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:32:41 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1);

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
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
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
