/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:39:25 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/21 15:46:16 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 10

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
////////////
# include <stdio.h>
////////////

typedef struct s_dot
{
	float	x;
	float	y;
	int		alt;
	int		color;
}	t_dot;

typedef struct s_data
{
	int		height;
	int		width;
	t_dot	**points;
	int		zoom;
	int		color;
	int		shift;
	int		shift_x;
	int		shift_y;

	int		screen_w;
	int		screen_h;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	get_map(t_data *data, char *argv);
void	draw(t_data *data, t_dot **points);
void	get_zoom(t_dot *a, t_dot *b, t_data *data);
void	get_color(int z, t_data *data);
void	change_shift(t_dot *a, t_dot *b, t_data *data);
void	isometric(t_dot *start, t_dot *end, int z, int z1);
void	errormsg(char *msg);

#endif	