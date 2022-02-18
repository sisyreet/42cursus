/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:00 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/18 13:11:04 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_data(t_data *data)
{
	free(data->stack_b);
	free(data->stack_a);
	free(data);
}

void	error_message(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_elem	*stack_a;
	t_elem	*stack_b;

	stack_a = 0;
	stack_b = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_message("Memory wasn't allocated!\n");
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	parse(argc, argv, data);
	free_data(data);
}
