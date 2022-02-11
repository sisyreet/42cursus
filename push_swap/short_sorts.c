/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:42:58 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/11 11:00:10 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(int *array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

void	sort_three_b(t_data *data)
{
	if (data->stack_b[0] > data->stack_b[1]
		&& data->stack_b[1] > data->stack_b[2])
	{
		swap_b(data);
		reverse_rotate_b(data);
	}
	if (data->stack_b[0] < data->stack_b[1]
		&& data->stack_b[1] > data->stack_b[2])
		reverse_rotate_b(data);
	if (data->stack_b[0] > data->stack_b[1]
		&& data->stack_b[0] < data->stack_b[2])
		swap_b(data);
	if (data->stack_b[0] > data->stack_b[1]
		&& data->stack_b[1] < data->stack_b[2])
		rotate_b(data);
}

void	sort_three_a(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
		reverse_rotate_a(data);
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] < data->stack_a[2])
		swap_a(data);
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2])
		rotate_a(data);
}

void	sort_five(t_data *data, int median)
{
	int	i;

	i = data->len_a;
	while (i)
	{
		if (data->stack_a[0] < median)
			push_b(data);
		else
			rotate_a(data);
		i--;
	}
	if (data->len_a == 3 && is_sorted(data->stack_a, data->len_a) == 0)
		sort_three_a(data);
	if (data->len_a < 3 && is_sorted(data->stack_a, data->len_a) == 0)
		swap_a(data);
	if (data->len_b == 3 && is_sorted(data->stack_b, data->len_b) == 0)
		sort_three_b(data);
	if (data->len_b < 3 && is_sorted(data->stack_b, data->len_b) == 1)
		swap_b(data);
	while (data->len_b)
		push_a(data);
}
