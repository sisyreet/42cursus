/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:20:30 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/27 16:38:26 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		points_free(data);
		exit(0);
	}
	return (0);
}

void	points_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height + 1)
	{	
		free(data->points[i]);
		i++;
	}
	free(data->points);
}

int	errormsg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			errormsg("Memory wasn't allocated! :<");
		data->scr_x = 2400;
		data->scr_y = 1020;
		get_map(data, argv[1]);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->scr_x, \
															data->scr_y, "fdf");
		data->zoom = 10;
		data->shift_x = data->scr_x / 2;
		data->shift_y = 0;
		draw(data, data->points);
		mlx_key_hook(data->win_ptr, key_hook, data);
		mlx_hook(data->win_ptr, 17, 0, errormsg, 0);
		mlx_loop(data->mlx_ptr);
	}
	else
		errormsg("Wrong number of arguments!");
	return (0);
}
