/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:23:26 by sisyreet          #+#    #+#             */
/*   Updated: 2021/12/02 12:20:11 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	has_nl(char *saved)
{
	int	s;

	s = 0;
	if (!saved)
		return (0);
	while (saved[s])
	{
		if (saved[s] == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*get_str_before_nl(char *saved)
{
	int		s;
	char	*truncated;

	s = 0;
	while (saved[s])
	{
		if (saved[s] == '\n')
			break ;
		s++;
	}
	truncated = (char *)malloc(sizeof(char) * s + 2);
	if (!truncated)
		return (0);
	truncated[s + 1] = 0;
	while (s >= 0)
	{
		truncated[s] = saved[s];
		s--;
	}
	if (truncated[0] == 0)
	{
		free(truncated);
		return (0);
	}
	return (truncated);
}

static char	*get_str_after_nl(char *saved)
{
	int		s;
	int		n;
	char	*new_str;

	if (!saved)
		return (0);
	s = 0;
	while (saved[s] != 0 && saved[s] != '\n')
		s++;
	if (saved[s] == 0)
	{
		free(saved);
		return (0);
	}
	new_str = (char *)malloc(sizeof(char) * ft_strlen(saved) - s + 1);
	if (!new_str)
		return (0);
	s++;
	n = 0;
	while (saved[s])
		new_str[n++] = saved[s++];
	new_str[n] = 0;
	free(saved);
	return (new_str);
}

char	*get_next_line(int fd)
{
	int			chars;
	char		*temp;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	chars = 1;
	while (chars != 0 && has_nl(saved) != 1)
	{
		chars = read(fd, temp, BUFFER_SIZE);
		if (chars == -1)
		{
			free(temp);
			return (0);
		}
		temp[chars] = 0;
		saved = ft_strjoin(saved, temp);
	}
	free(temp);
	temp = get_str_before_nl(saved);
	saved = get_str_after_nl(saved);
	return (temp);
}
