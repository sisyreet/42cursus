/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:52:56 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/08 12:27:27 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words((char *)str, c) + 1));
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			arr[j] = malloc_word((char *)&str[i], c);
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
