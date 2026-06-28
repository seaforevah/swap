/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:27:01 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/27 18:45:37 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof (t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->pos = 0;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	t_node	*n;

	n = new_node(42);
	printf("%d\n", n->value);
}*/