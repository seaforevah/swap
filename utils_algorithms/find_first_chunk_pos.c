/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_chunk_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:42:54 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/28 18:28:20 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_chunk_pos(t_node *a, int start, int end, int *pos_out)
{
	int	pos;
	int	best_pos;
	int	best_index;
	int	found;

	pos = 0;
	found = 0;
	best_index = 0;
	best_pos = 0;
	while (a)
	{
		if (a->index >= start && a->index <= end
			&& (!found || a->index < best_index))
		{
			best_index = a->index;
			best_pos = pos;
			found = 1;
		}
		pos++;
		a = a->next;
	}
	if (!found)
		return (0);
	*pos_out = best_pos;
	return (1);
}
