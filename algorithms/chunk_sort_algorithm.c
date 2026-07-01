/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:14:42 by crmatas-          #+#    #+#             */
/*   Updated: 2026/07/01 20:28:16 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_algorithm(t_push_swap *ps)
{
	assign_indexes(ps->a);
	ps->bench.strategy = "Chunk Sort";
	ps->bench.complexity = "O(n*sqrt(n))";
	push_chunks_to_b(ps, get_chunk_size(ps->size_a));
	push_back_to_a(ps);
}
