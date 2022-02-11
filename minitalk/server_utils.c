/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:26:59 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/04 12:43:22 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_putchar_fd(int n, int fd)
{	
	char	c;

	if (n < 10)
	{
		c = n % 10 + '0';
	}
	else if (n >= 10)
	{
		ft_putchar_fd(n / 10, fd);
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
		ft_putchar_fd (n, fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putchar_fd (n, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
