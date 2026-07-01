/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:13:32 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/16 16:13:45 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*new;
	size_t			size;
	size_t			i;

	size = ft_strlen(s);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return ((char *)new);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_strdup("hola cara cola");
	if (result)
	{
		printf ("%s", result);
		free(result);
	}
	return (0);
}*/