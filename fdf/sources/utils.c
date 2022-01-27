/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:54:10 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/27 10:47:33 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_alt_and_color(t_dot *zets, char *alt)
{
	zets->alt = ft_atoi(alt);
	if (zets->alt <= -9)
		zets->color = 0xe5c9ff;
	if (zets->alt > -9)
		zets->color = 0xc9d2ff;
	if (zets->alt > -7)
		zets->color = 0xc9e9ff;
	if (zets->alt > -5)
		zets->color = 0xc9f8ff;
	if (zets->alt > -3)
		zets->color = 0xc9ffe0;
	if (zets->alt > -1)
		zets->color = 0xdbffc9;
	if (zets->alt == 0)
		zets->color = 0xdbffc9;
	if (zets->alt > 1)
		zets->color = 0xfff9c9;
	if (zets->alt > 3)
		zets->color = 0xffe2b0;
	if (zets->alt > 5)
		zets->color = 0xffd4b0;
	if (zets->alt > 7)
		zets->color = 0xffbdb0;
	if (zets->alt > 9)
		zets->color = 0xffb0b0;
}

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
	start->y = (start->x + start->y) * sin(1.2) - z;
	end->x = (end->x - end->y) * cos(1.0);
	end->y = (end->x + end->y) * sin(1.2) - z1;
}
