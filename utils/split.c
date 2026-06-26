/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:27:38 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/09 19:32:34 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	c_words;
	size_t	i;

	c_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			c_words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (c_words);
}

static char	**ft_make_matrix(char const *s, char **matrix, char c,
							size_t c_words)
{
	size_t	start;
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	while (c_words > row)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		matrix[row] = ft_substr(s, start, i - start);
		if (!matrix[row])
		{
			free_mtx(matrix);
			return (NULL);
		}
		row++;
	}
	matrix[row] = NULL;
	return (matrix);
}

char	**split(char const *s, char c)
{
	char	**matrix;
	size_t	c_words;

	c_words = ft_count_words(s, c);
	matrix = malloc(sizeof (char *) * (c_words + 1));
	if (!matrix)
		return (NULL);
	if (!(ft_make_matrix(s, matrix, c, c_words)))
		return (NULL);
	return (matrix);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	size_t	i;

	char	*str = "hola cara de cola";
	result = ft_split(str, ' ');
	i = 0;
	while (result)
	{
	
		i++;
	}

	printf ("%s\n", result[0]);
	printf ("%s\n", result[1]);
	printf ("%s\n", result[2]);
	printf ("%s\n", result[3]);
	free (result);
}
*/