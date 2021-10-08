/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:36:27 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 17:36:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
