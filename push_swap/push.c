/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:04 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 16:12:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_b(t_data *data)
{
	int	temp;
	int	i;

	if (data->len_a)
	{
		temp = data->stack_a[0];
		i = 0;
		while (i < data->len_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = 0;
		data->len_a -= 1;
		data->len_b += 1;
		i = data->len_b;
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[i] = temp;
		write(1, "pb\n", 3);
	}
}

// void	push_b(t_data *data)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	temp = data->stack_a[i];
// 	while (i < data->len_a - 1)
// 	{
// 		data->stack_a[i] = data->stack_a[i + 1];
// 		i++;
// 	}
// 	data->stack_a[i] = temp;
// 	data->len_a -= 1;
// 	data->len_b += 1;
// 	i = data->len_b;
// 	while (i > 0)
// 	{
// 		data->stack_b[i] = data->stack_b[i - 1];
// 		i--;
// 	}
// 	data->stack_b[i] = temp;
// }

void	push_a(t_data *data)
{
	int	temp;
	int	i;

	if (data->len_b)
	{
		temp = data->stack_b[0];
		i = 0;
		while (i < data->len_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[--i] = 0;
		data->len_b -= 1;
		data->len_a += 1;
		i = data->len_a;
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[i] = temp;
		write(1, "pa\n", 3);
	}
}

void	rotate_rotate(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	write(1, "rr\n", 3);
}
