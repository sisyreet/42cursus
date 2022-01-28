/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:41:17 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/28 19:57:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_byte(int pid, char c)
{
	int		div;
	char	byte_to_send;

	div = 128;
	while (div > 0)
	{
		if ((c & div) > 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		div /= 2;
		sleep(1);
	}
}

void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		send_byte(pid, msg[i++]);
}

int	main(int args, char **argv)
{
	int		pid;
	char	*msg;

	if (args != 3)
		error_message("usage: ./client [server pid] [your message]\n");
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		error_message("Incorrect server pid! >:(\n");
	msg = argv[2];
	send_message(pid, msg);
}
