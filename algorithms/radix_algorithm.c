/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:05:10 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/28 23:43:32 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_algorithm(t_push_swap *ps)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	ps->bench.strategy = "Radix Sort";
	ps->bench.complexity = "O(n log n)";
	size = ps->size_a;
	max_bits = get_max_bits(ps);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((ps->a->index >> i) & 1) == 1)
				ra(ps);
			else
				pb(ps);
			j++;
		}
		while (ps->b)
			pa(ps);
		i++;
	}
}
