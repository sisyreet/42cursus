/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:50:54 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:43:38 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int n, int fd)
{	
	char	c;

	if (n < 10)
	{
		c = n % 10 + '0';
	}
	else if (n >= 10)
	{
		ft_putchar(n / 10, fd);
		c = n % 10 + '0';
	}
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == (-2147483648))
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n > 0)
		ft_putchar (n, fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putchar (n, fd);
	}
}
