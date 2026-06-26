/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:05:10 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/19 19:07:26 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_algorithm(t_push_swap *ps)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

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
