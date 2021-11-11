/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:42:56 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/11 14:03:54 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_put_c(va_list ap);
int		ft_put_d_i(va_list ap);
int		ft_put_u(va_list ap);
int		ft_put_s(va_list ap);
int		ft_put_x(va_list ap, char spec);
int		ft_put_p(va_list ap);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif