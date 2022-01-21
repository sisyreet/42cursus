/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:54:19 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/21 15:45:13 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	sy_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	sy_mod(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	line(t_dot start, t_dot end, t_data *data)
{
	float	dx;
	float	dy;
	int		max;

	get_zoom(&start, &end, data);
	isometric(&start, &end, start.alt, end.alt);
	change_shift(&start, &end, data);
	dx = end.x - start.x;
	dy = end.y - start.y;
	max = sy_max(sy_mod(dx), sy_mod(dy));
	dx /= max;
	dy /= max;
	if (start.alt < end.alt)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x, \
													start.y, start.color);
		start.x += dx;
		start.y += dy;
	}
}

void	draw(t_data *data, t_dot **points)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				line(points[y][x], points[y][x + 1], data);
			if (y < data->height - 1)
				line(points[y][x], points[y + 1][x], data);
			x++;
		}
		y++;
	}
}
			// if (y < data->height - 1 && x < data->width - 1)
			// 	line(points[y][x], points[y + 1][x + 1], data);
			// if (y > 0 && x < data->width - 1)
			// 	line(points[y][x], points[y - 1][x + 1], data);
