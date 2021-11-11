/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:35:15 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 14:29:51 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_dec_to_uphex(unsigned int num)
{
	long	rem;
	long	qou;
	char	arr[100];
	int		a;

	qou = num;
	a = 0;
	if (num < 0)
	{
		num = 4294967295 + num;
	}
	while (qou != 0)
	{
		rem = qou % 16;
		if (rem < 10)
			arr[a++] = 48 + rem;
		else
			arr[a++] = 55 + rem;
		qou = qou / 16;
	}
	arr[a--] = 0;
	while (a >= 0)
		ft_putchar(arr[a--]);
	return (ft_strlen(arr));
}

int	ft_dec_to_lowhex(unsigned int num)
{
	long	rem;
	long	qou;
	char	arr[100];
	int		a;

	qou = num;
	a = 0;
	{
		num = 4294967295 + num;
	}
	while (qou != 0)
	{
		rem = qou % 16;
		if (rem < 10)
			arr[a++] = 48 + rem;
		else
			arr[a++] = 87 + rem;
		qou = qou / 16;
	}
	arr[a--] = 0;
	while (a >= 0)
		ft_putchar(arr[a--]);
	return (ft_strlen(arr));
}

int	ft_put_x(va_list ap, char spec)
{
	unsigned int	num;

	num = va_arg(ap, int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (spec == 'x')
		return (ft_dec_to_lowhex(num));
	else
		return (ft_dec_to_uphex(num));
}
