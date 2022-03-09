/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:22 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 12:21:00 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap_b(t_data *data)
{
	t_elem	temp;

	if (data->length_b > 1)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
	}
	data->count++;
}

void	swap_a(t_data *data)
{
	t_elem	temp;

	if (data->length_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
	}
	data->count++;
}
