/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:00:40 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/30 21:36:12 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*This function performs the reverse rotate operation on a given stack. 
It checks if the stack has at least two elements, and if so, 
it moves the last element to the beginning of the stack. The 'rra', 'rrb',
and 'rrr' functions call this reverse rotate function for stack A, stack B,
or both stacks respectively, and also handle the output and benchmarking 
of the operations.*/

void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*aux;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		aux = last;
		last = last->next;
	}
	aux->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_push_swap *ps)
{
	rev_rotate(&ps->a);
	if (!ps->count_only)
		write(1, "rra\n", 4);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RRA]++;
	}
}

void	rrb(t_push_swap *ps)
{
	rev_rotate(&ps->b);
	if (!ps->count_only)
		write(1, "rrb\n", 4);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RRB]++;
	}
}

void	rrr(t_push_swap *ps)
{
	rev_rotate(&ps->a);
	rev_rotate(&ps->b);
	if (!ps->count_only)
		write(1, "rrr\n", 4);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RRR]++;
	}
}
