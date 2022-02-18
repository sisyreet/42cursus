/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:17 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/17 13:06:17 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_index(t_data *data)
{
	int	max;
	int	i;

	max = data->stack_b[0].index;
	i = 0;
	while (i < data->length_b)
	{
		if (data->stack_b[i].index > max)
			max = data->stack_b[i].index;
		i++;
	}
	return (max);
}

void	second_sort(t_data *data)
{
	int	len;
	int	mid;

	while (data->length_b)
	{
		data->max_index = find_max_index(data);
		len = data->length_b - 1;
		mid = data->length_b / 2;
		if (data->stack_b[0].index != data->max_index
			&& calculate_price(data) == 'u')
			rotate_b(data);
		else if (data->stack_b[0].index != data->max_index
			&& calculate_price(data) == 'd')
			reverse_rotate_b(data);
		else if (data->stack_b[0].index == data->max_index)
			push_a(data);
	}
}

void	sort_aft_300(t_data *data)
{
	int	i;

	i = 0;
	while (data->length_a)
	{
		if (i > 1 && data->stack_a[0].index <= i)
		{
			push_b(data);
			i++;
			rotate_b(data);
		}
		else if (data->stack_a[0].index <= i + 30)
		{
			push_b(data);
			i++;
		}
		else
			rotate_a(data);
	}
	second_sort(data);
}

void	sort_bef_300(t_data *data)
{
	int	i;

	i = 0;
	while (data->length_a)
	{
		if (i > 1 && data->stack_a[0].index <= i)
		{
			push_b(data);
			i++;
			rotate_b(data);
		}
		else if (data->stack_a[0].index <= i + 15)
		{
			push_b(data);
			i++;
		}
		else
			rotate_a(data);
	}
	second_sort(data);
}

void	long_sorts(t_data *data)
{	
	t_elem	*buf;

	buf = buf_malloc(data);
	set_indexes(data, buf);
	if (data->length_a < 6)
		sort_five(data);
	if (data->length_a > 5 && data->length_a < 300)
		sort_bef_300(data);
	if (data->length_a > 299)
		sort_aft_300(data);
	free(buf);
}
