/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:08:01 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 15:12:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_dec_to_lowhex_l(unsigned long long num)
{
	unsigned long long	rem;
	unsigned long long	qou;
	char				arr[100];
	int					a;

	qou = num;
	a = 0;
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

int	ft_put_p(va_list ap)
{
	void				*ptr;
	unsigned long long	adr;

	ptr = va_arg(ap, void *);
	adr = (unsigned long long)ptr;
	if (!ptr)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (ft_dec_to_lowhex_l(adr) + 2);
}
