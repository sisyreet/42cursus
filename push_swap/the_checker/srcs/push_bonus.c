/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:50:54 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/18 19:07:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_elem	set_nulls(t_elem elem)
{
	elem.index = 0;
	elem.value = 0;
	return (elem);
}

void	push_b(t_data *data)
{
	t_elem	temp;
	int		i;

	if (data->length_a)
	{
		temp = data->stack_a[0];
		i = 0;
		while (i < data->length_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = set_nulls(data->stack_a[i]);
		data->length_a -= 1;
		data->length_b += 1;
		i = data->length_b;
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[i] = temp;
	}
}

void	push_a(t_data *data)
{
	t_elem	temp;
	int		i;

	if (data->length_b)
	{
		temp = data->stack_b[0];
		i = 0;
		while (i < data->length_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = set_nulls(data->stack_b[i]);
		data->length_a += 1;
		data->length_b -= 1;
		i = data->length_a;
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[0] = temp;
	}
}
