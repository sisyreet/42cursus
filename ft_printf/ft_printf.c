/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:19:32 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 14:04:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_specs(va_list ap, char spec)
{
	if (spec == '%')
		return (ft_putchar(spec));
	if (spec == 'c')
		return (ft_put_c(ap));
	if (spec == 'd' || spec == 'i')
		return (ft_put_d_i(ap));
	if (spec == 'u')
		return (ft_put_u(ap));
	if (spec == 's')
		return (ft_put_s(ap));
	if (spec == 'x' || spec == 'X')
		return (ft_put_x(ap, spec));
	if (spec == 'p')
		return (ft_put_p(ap));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		total;
	va_list	ap;

	va_start(ap, fmt);
	total = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if ((char)fmt[i] == '%')
		{
			i++;
			total += ft_specs(ap, fmt[i]);
			i++;
		}
		else
		{
			write (1, &fmt[i], 1);
			total++;
			i++;
		}
	}
	va_end(ap);
	return (total);
}
