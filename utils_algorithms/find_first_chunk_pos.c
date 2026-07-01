/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_chunk_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:42:54 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/20 23:56:12 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_chunk_pos(t_node *a, int start, int end, int *pos_out)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= start && a->index <= end)
		{
			*pos_out = pos;
			return (1);
		}
		pos++;
		a = a->next;
	}
	return (0);
}
