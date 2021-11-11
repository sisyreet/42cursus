/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:19:55 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 14:04:20 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_u(unsigned int n)
{	
	char		c;
	static int	count;

	count = 0;
	if (n < 10)
		c = n % 10 + '0';
	else if (n >= 10)
	{
		ft_putchar_u(n / 10);
		c = n % 10 + '0';
	}
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n > 0)
		count = ft_putchar_u(n);
	return (count);
}

int	ft_put_u(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	return (ft_putnbr_u(num));
}
