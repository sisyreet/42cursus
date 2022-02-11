/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:41:17 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 13:39:45 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

volatile sig_atomic_t	g_flag = 1;

void	send_bit(pid_t pid, int signum)
{
	if (signum == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
			error_message("Can't reach the server! Wrong PID maybe?");
	}		
	else if (signum == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
			error_message("Can't reach the server! Wrong PID maybe?");
	}
}

void	send_message(int pid, char *msg)
{
	int	i;
	int	div;
	int	panic;

	i = 0;
	while (msg[i])
	{
		div = 128;
		panic = 0;
		while (div > 0)
		{
			if (g_flag == 1)
			{	
				g_flag = 0;
				if ((msg[i] & div) > 0)
					send_bit(pid, 1);
				else
					send_bit(pid, 0);
				div /= 2;
			}
			if (panic++ > 1234567890)
				error_message("\nServer doesn't respond! :(\n");
		}
		i++;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag = 1;
}

void	check_args(int args, char **argv)
{
	int		pid;

	if (args < 3)
		error_message("usage: ./client [server pid] [your message]");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_message("PID must be > 0!");
	if (args > 3)
		error_message("Use \"quotes\" to send several words in one message");
}

int	main(int args, char **argv)
{
	int					pid;
	char				*msg;
	struct sigaction	siga;

	check_args(args, argv);
	msg = argv[2];
	pid = ft_atoi(argv[1]);
	siga.sa_flags = SA_SIGINFO;
	siga.sa_handler = signal_handler;
	sigaction(SIGUSR1, &siga, NULL);
	send_message(pid, msg);
	ft_putstr_fd("\nThe message was delivered to server!\n", 1);
	return (0);
}
