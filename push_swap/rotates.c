/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:14:52 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 16:20:37 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	reverse_rotate_b(t_data *data)
{
	int	temp;
	int	i;

	i = data->len_a - 1;
	temp = data->stack_b[data->len_a - 1];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[i] = temp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a(t_data *data)
{
	int	temp;
	int	i;

	i = data->len_a - 1;
	temp = data->stack_a[data->len_a - 1];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[i] = temp;
	write(1, "rra\n", 4);
}

void	rotate_b(t_data *data)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = data->stack_b[i];
	i++;
	while (i < data->len_b)
	{
		data->stack_b[i - 1] = data->stack_b[i];
		i++;
	}
	data->stack_b[--i] = temp;
	write(1, "rb\n", 3);
}

void	rotate_a(t_data *data)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = data->stack_a[i];
	i++;
	while (i < data->len_a)
	{
		data->stack_a[i - 1] = data->stack_a[i];
		i++;
	}
	data->stack_a[--i] = temp;
	write(1, "ra\n", 3);
}
