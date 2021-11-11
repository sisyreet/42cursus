/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:19:55 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 14:04:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_fd(int n)
{	
	char		c;
	static int	count;

	count = 0;
	if (n < 10)
		c = n % 10 + '0';
	else if (n >= 10)
	{
		ft_putchar_fd(n / 10);
		c = n % 10 + '0';
	}
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == (-2147483648))
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n > 0)
		count = ft_putchar_fd(n);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count = ft_putchar_fd(n);
		count++;
	}
	return (count);
}

int	ft_put_d_i(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	return (ft_putnbr(num));
}
