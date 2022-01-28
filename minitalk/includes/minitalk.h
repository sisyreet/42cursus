/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:43:57 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/28 19:52:24 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
/*					*/
# include <stdio.h>
/*					*/
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	int		client_pid;
	char	c;
}		t_data;

void	error_message(char *msg);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(char *line);
void	ft_putchar_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);


#endif