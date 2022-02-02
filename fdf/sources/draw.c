/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:54:19 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/02 10:18:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	sy_max(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
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
	max = sy_max(dx, dy);
	dx /= max;
	dy /= max;
	if (start.alt < end.alt)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.x >= 0 && (int)start.y >= 0)
			ft_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += dx;
		start.y += dy;
	}
}

void	draw(t_data *data, t_dot **points)
{
	int	x;
	int	y;

	y = 0;
	ft_memset((int *)(data)->addr, BG_COLOR, \
						data->scr_x * data->scr_y * (data->bits_per_pixel / 8));
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				line(points[y][x], points[y][x + 1], data);
			if (y < data->height - 1)
				line(points[y][x], points[y + 1][x], data);
			if (y < data->height - 1 && x < data->width - 1)
				line(points[y][x], points[y + 1][x + 1], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
