/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:43:07 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/28 19:54:30 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	signal_handler(int signal_number, siginfo_t *siginfo, void *context)
{
	if (signal_number == 0)
		printf("0!");
	else if (signal_number == 1)
		printf("1!");
	else
		printf(":(");
}

void	welcome_message(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	siga;

	welcome_message();
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while(1)
		sleep(1);
}
