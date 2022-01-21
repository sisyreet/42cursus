/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:20:30 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/21 16:06:47 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 53)
		exit(0);
	if (key == 69)
		data->zoom += 5;
	if (key == 78)
	{
		if (data->zoom > 15)
			data->zoom -= 5;
	}
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

void	errormsg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit(17);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_dot	screen;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(data));
		screen.x = 2400;
		screen.y = 1080;
		get_map(data, argv[1]);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, screen.x, \
															screen.y, "FdF");
		data->color = 0x03fc07;
		data->zoom = 30;
		data->shift_x = screen.x / 2;
		data->shift_y = 0;
		draw(data, data->points);
		mlx_key_hook(data->win_ptr, key_hook, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		errormsg("Wrong number of arguments!");
	return (0);
}
