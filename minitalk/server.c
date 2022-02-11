/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:43:07 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/04 15:41:22 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

t_flag	g_flag;

void	reset_data(int *cpid, pid_t *pid, char *ch, int *div)
{
	*cpid = *pid;
	*ch = 0;
	*div = 128;
	write(1, "\n", 1);
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	cpid = 0;
	static int	div = 128;
	static char	ch = 0;

	(void)context;
	if (cpid != siginfo->si_pid)
		reset_data(&cpid, &siginfo->si_pid, &ch, &div);
	if (signum == SIGUSR2)
		ch += div;
	div /= 2;
	if (!div)
	{	
		write(1, &ch, 1);
		div = 128;
		ch = 0;
	}
	g_flag.flag = 1;
	g_flag.cpid = siginfo->si_pid;
}

void	welcome_message(void)
{
	ft_putstr_fd("Server's PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
}

int	main(void)
{
	struct sigaction	siga;

	welcome_message();
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
	{
		while (g_flag.flag != 1)
			;
		g_flag.flag = 0;
		kill(g_flag.cpid, SIGUSR1);
	}
}
