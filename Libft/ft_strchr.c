/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:25:36 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 17:51:40 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	int		s;

	s = 0;
	while (str[s])
	{
		if ((char)ch == str[s])
		{
			return ((char *) &str[s]);
		}
		s++;
	}
	if ((char)ch == 0)
		return ((char *) &str[s]);
	return (0);
}
