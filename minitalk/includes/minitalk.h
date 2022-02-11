/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:43:57 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/04 16:00:44 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	volatile sig_atomic_t	cpid;
	volatile sig_atomic_t	flag;
}	t_flag;

void	error_message(char *msg);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(char *line);
void	ft_putchar_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif