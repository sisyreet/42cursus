/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:50:37 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/27 15:08:54 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	get_zoom(t_dot *a, t_dot *b, t_data *data)
{
		a->x *= data->zoom;
		a->y *= data->zoom;
		a->alt *= (data->zoom / 15);
		b->x *= data->zoom;
		b->y *= data->zoom;
		b->alt *= (data->zoom / 15);
}

int	key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		points_free(data);
		exit(0);
	}
	if (key == 69)
		if (data->zoom < 210)
			data->zoom += 15;
	if (key == 78)
		if (data->zoom > 15)
			data->zoom -= 15;
	if (key == 123)
		data->shift_x += 75;
	if (key == 124)
		data->shift_x -= 75;
	if (key == 125)
		data->shift_y -= 75;
	if (key == 126)
		data->shift_y += 75;
	draw(data, data->points);
	return (0);
}
