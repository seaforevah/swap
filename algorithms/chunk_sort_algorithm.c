/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:14:42 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/28 23:43:55 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_algorithm(t_push_swap *ps)
{
	int	chunk_size;
	int	start;
	int	end;
	int	pos;

	ps->bench.strategy = "Chunk Sort";
	ps->bench.complexity = "O(n*sqrt(n))";
	chunk_size = get_chunk_size(ps->size_a);
	start = 0;
	end = chunk_size - 1;
	while (stack_size(ps->a) > 0)
	{
		update_position(ps->a);
		while (find_first_chunk_pos(ps->a, start, end, &pos) == 1)
		{
			bring_to_top_a(ps, pos);
			pb(ps);
		}
		start += chunk_size;
		end += chunk_size;
	}
	while (stack_size(ps->b) > 0)
		pa(ps);
}
