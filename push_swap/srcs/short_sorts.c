/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:19 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/18 10:29:54 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_b(t_data *data)
{
	if (data->stack_b[0].index > data->stack_b[1].index
		&& data->stack_b[1].index > data->stack_b[2].index)
	{
		swap_b(data);
		reverse_rotate_b(data);
	}
	if (data->stack_b[0].index < data->stack_b[1].index
		&& data->stack_b[1].index > data->stack_b[2].index)
		reverse_rotate_b(data);
	if (data->stack_b[0].index > data->stack_b[1].index
		&& data->stack_b[0].index < data->stack_b[2].index)
		swap_b(data);
	if (data->stack_b[0].index > data->stack_b[1].index
		&& data->stack_b[1].index < data->stack_b[2].index)
		rotate_b(data);
}

void	sort_three_a(t_data *data)
{
	if (data->length_a == 2 && data->stack_a[0].value > data->stack_a[1].value)
	{
		swap_a(data);
		return ;
	}
	if (data->length_a == 2 && is_sorted(data->stack_a, data->length_a))
		return ;
	if (data->stack_a[0].index > data->stack_a[1].index
		&& data->stack_a[1].index > data->stack_a[2].index)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	if (data->stack_a[0].index < data->stack_a[1].index
		&& data->stack_a[1].index > data->stack_a[2].index)
		reverse_rotate_a(data);
	if (data->stack_a[0].index > data->stack_a[1].index
		&& data->stack_a[0].index < data->stack_a[2].index)
		swap_a(data);
	if (data->stack_a[0].index > data->stack_a[1].index
		&& data->stack_a[1].index < data->stack_a[2].index)
		rotate_a(data);
}

void	sort_five(t_data *data)
{
	data->max_index = data->length_a;
	while (data->length_a > 3)
		push_b(data);
	sort_three_a(data);
	if (data->stack_b[0].index < data->stack_b[1].index)
		swap_b(data);
	if (data->stack_b[0].index == data->max_index)
		push_a(data);
	while (data->length_b)
	{
		if (data->stack_a[data->length_a - 1].index
			== data->stack_b[0].index + 1)
			reverse_rotate_a(data);
		if (data->stack_a[0].index == data->stack_b[0].index + 1)
			push_a(data);
		else
			rotate_a(data);
	}
	if (data->stack_a[0].index > 2)
		while (data->stack_a[0].index != 1)
			rotate_a(data);
	else
		while (data->stack_a[0].index != 1)
			reverse_rotate_a(data);
}
