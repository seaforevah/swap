/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:14:42 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/25 12:13:01 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_algorithm(t_push_swap *ps)
{
	int	chunk_size;
	int	start;
	int	end;
	int	pos;

	chunk_size = get_chunk_size(ps->size_a);
	start = 0;
	end = chunk_size - 1;
	while (ps->size_a > 0)
	{
		update_position(ps->a);
		pos = find_first_chunk_pos(ps->a, start, end, &pos);
		while (pos == 1)
		{
			bring_to_top(ps, pos);
			pb(ps);
		}
		start += chunk_size;
		end += chunk_size;
	}
}
