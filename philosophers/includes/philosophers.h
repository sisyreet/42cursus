/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:32:48 by sisyreet          #+#    #+#             */
/*   Updated: 2022/03/22 18:42:11 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h> 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_fork
{
	t_mutex		mutex;
}	t_fork;

typedef struct s_phil
{
	pthread_t	id;
	t_mutex		left_fork;
	t_mutex 	right_fork;
	
	int			last_time_eat;
	int			number_of_eats;
}	t_phil;

typedef struct s_data
{
	int			num_of_phils;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eats;
	
	t_phil		*phil;
}	t_data;

int	ft_atoi(const char *nptr);
int	ermessage(char *msg);
void	init_data(int argc, char **argv, t_data *data);
size_t	ft_strlen(const char *s);

#endif