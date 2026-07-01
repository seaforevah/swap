/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:31:12 by crmatas-          #+#    #+#             */
/*   Updated: 2026/05/31 17:10:34 by crmatas-         ###   ########.fr       */
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