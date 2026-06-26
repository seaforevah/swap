/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:19:05 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/20 23:58:34 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_chunk(t_node *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (1);
		a = a->next;
	}
	return (0);
}
