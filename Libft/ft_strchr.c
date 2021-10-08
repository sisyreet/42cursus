/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:25:36 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/06 19:28:50 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	int		s;

	s = 0;
	if (str[s] == 0)
		return ((char *) &str[s]);
	while (str[s])
	{
		if (ch == str[s])
		{
			return ((char *) &str[s]);
		}
		s++;
	}
	return (0);
}
