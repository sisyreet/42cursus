/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:41:58 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 18:02:40 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	any_error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	mem_error_msg(void)
{
	write(2, "Memory wasn't allocated! :( \n", 29);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		*stack_a;
	int		*stack_b;

	stack_a = 0;
	stack_b = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		mem_error_msg();
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->len_b = 0;
	check_args(argc, argv, data);
	sorting(data);
	print_stacks(data);
}
