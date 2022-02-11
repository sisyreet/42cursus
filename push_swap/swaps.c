/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:42:12 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 13:14:51 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_a(t_data *data)
{
	int	temp;

	temp = 0;
	temp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = temp;
	write (1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	int	temp;

	temp = 0;
	temp = data->stack_b[0];
	data->stack_b[0] = data->stack_b[1];
	data->stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	swap_ss(t_data *data)
{
	swap_a(data);
	swap_b(data);
	write(1, "ss\n", 3);
}
