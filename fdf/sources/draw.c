/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:04:33 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/11 11:52:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, void *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	draw_something(t_point *points, t_map map_size)
{
	void	*mlx_ptr;	
	void	*win_prt;
	int		p;
	int		y;
	int		x;

	y = 0;
	p = 0;
	x = 20;
	y = 20;
	mlx_ptr = mlx_init();
	win_prt = mlx_new_window(mlx_ptr, 1024, 768, "Test RuN");
	while (p < (map_size.x * map_size.y))
	{
		if (points[p].y > points[p - 1].y)
			y += 20;
		if (points[p].x < points[p - 1].x)
			x = 20;
		mlx_pixel_put(mlx_ptr, win_prt, x, y, 0xFFFFFF);
		x += 20;
		p++;
	}
	mlx_string_put(mlx_ptr, win_prt, 0, 0, 0xDDDDDD, "Hello!");
	mlx_key_hook(win_prt, key_hook, (void *)0);
	mlx_loop(mlx_ptr);
}
