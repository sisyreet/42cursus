/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:39:25 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/11 14:24:23 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 10

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
////////////
# include <stdio.h>
////////////

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	draw_something(t_point *point, t_map map_size);

#endif	