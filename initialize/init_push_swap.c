/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:33:32 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/30 18:15:01 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_push_swap *ps)
{
	int	i;

	ps->strategy = ADAPTIVE;
	ps->has_strategy = 0;
	ps->bench.active = 0;
	ps->bench.total_ops = 0;
	ps->count_only = 0;
	ps->bench.strategy = "Already sorted";
	ps->bench.complexity = "O(n)";
	i = 0;
	while (i < 11)
	{
		ps->bench.op_counts[i] = 0;
		i++;
	}
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
}

/*
Pointers are initialise as NULL, and integers as 0.
initialise default strategy on adaptive in case there is non flags,
this would be the strategy taken.
has_strategy = 0; initialise boolen on 0 and store result if flag is found
and overwrite 1 if another flag is found then would check ir has 1 as a 
value and would give error on parse funtion.
same with bench, controls the flag --bench 
*/