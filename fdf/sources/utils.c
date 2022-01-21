/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:54:10 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/21 14:28:02 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_shift(t_dot *start, t_dot *end, t_data *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

void	get_zoom(t_dot *a, t_dot *b, t_data *data)
{
		a->x *= data->zoom;
		a->y *= data->zoom;
		a->alt *= (data->zoom / 15);
		b->x *= data->zoom;
		b->y *= data->zoom;
		b->alt *= (data->zoom / 15);
}

void	isometric(t_dot *start, t_dot *end, int z, int z1)
{
	start->x = (start->x - start->y) * cos(1.0);
	start->y = (start->x + start->y) * sin(1.1) - z;
	end->x = (end->x - end->y) * cos(1.0);
	end->y = (end->x + end->y) * sin(1.1) - z1;
}
