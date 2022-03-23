/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:23:39 by sisyreet          #+#    #+#             */
/*   Updated: 2022/03/22 18:13:00 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	ermessage(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (-1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	init_data(argc, argv, data);
}
