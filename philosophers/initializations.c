/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:56:15 by sisyreet          #+#    #+#             */
/*   Updated: 2022/03/22 19:23:06 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	*routine(void *data)
{
	printf("THIS! IS! SPARTA!\n");
	return (void *)NULL;
}

void	init_philosophers(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		data->phil[i].id = (pthread_t)i;
		pthread_create(&data->phil[i].id, NULL, &routine, (void *)&data->phil[i]);
		i++;
	}
	i = 0;
	while (i < data->num_of_phils)
	{
		pthread_join(data->phil[i].id, NULL);
		i++;
	}
}

void	init_data(int argc, char **argv, t_data *data)
{

	if (argc >= 5 && argc <= 6)
	{
		data->num_of_phils = ft_atoi(argv[1]);
		if (!(data->phil = malloc(sizeof(t_phil) * data->num_of_phils)))
			ermessage("Memory alloc error!\n");
		data->time_to_die = ft_atoi(argv[2]) * 1000;
		data->time_to_eat = ft_atoi(argv[3]) * 1000;
		data->time_to_sleep = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			data->num_of_eats = ft_atoi(argv[5]);
		else
			data->num_of_eats = -112;
		init_philosophers(data);
	}
	else
		ermessage("Usage: [number_of_philosophers] [time_to_die] [time_to_eat] \
[time_to_sleep] (optional)[number_of_times_each_philosopher_must_eat]\n");
}