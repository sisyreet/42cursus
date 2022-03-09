/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:14 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 10:03:26 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	reverse_rotate_b(t_data *data)
{
	t_elem	temp;
	int		i;

	i = data->length_b - 1;
	temp = data->stack_b[data->length_b - 1];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[i] = temp;
	data->count++;
}

void	rotate_b(t_data *data)
{
	t_elem	temp;
	int		i;

	i = 0;
	temp = data->stack_b[i];
	i++;
	while (i < data->length_b)
	{
		data->stack_b[i - 1] = data->stack_b[i];
		i++;
	}
	data->stack_b[--i] = temp;
	data->count++;
}

void	reverse_rotate_a(t_data *data)
{
	t_elem	temp;
	int		i;

	i = data->length_a - 1;
	temp = data->stack_a[data->length_a - 1];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[i] = temp;
	data->count++;
}

void	rotate_a(t_data *data)
{
	t_elem	temp;
	int		i;

	i = 0;
	temp = data->stack_a[i];
	i++;
	while (i < data->length_a)
	{
		data->stack_a[i - 1] = data->stack_a[i];
		i++;
	}
	data->stack_a[--i] = temp;
	data->count++;
}
