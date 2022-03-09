/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:12:56 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 10:41:57 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_elem	*buf_malloc(t_data *data)
{
	t_elem	*buf;
	int		i;

	buf = (t_elem *)malloc(sizeof(t_elem) * data->length_a + 1);
	if (!buf)
		error_message("Memory wasn't allocated!\n");
	i = 0;
	while (i < data->length_a)
	{
		buf[i] = data->stack_a[i];
		i++;
	}
	bubble_sort(data, buf);
	return (buf);
}

void	set_indexes(t_data *data, t_elem *buf)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->length_a)
	{
		j = 0;
		while (j < data->length_a)
		{
			if (data->stack_a[i].value == buf[j].value)
				data->stack_a[i].index = j + 1;
			j++;
		}
		i++;
	}
}

t_elem	*bubble_sort(t_data *data, t_elem *buf)
{
	t_elem	temp;
	int		i;
	int		count;

	count = 1;
	while (count)
	{
		i = 0;
		count = 0;
		while (i < data->length_a - 1)
		{
			if (buf[i].value > buf[i + 1].value)
			{
				temp = buf[i];
				buf[i] = buf[i + 1];
				buf[i + 1] = temp;
				count++;
			}
			i++;
		}
	}
	return (buf);
}

char	calculate_price(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->length_b / 2)
	{
		if (data->stack_b[i].index == data->max_index)
			return ('u');
		i++;
	}
	return ('d');
}
