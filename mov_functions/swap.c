/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:25:18 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/30 21:34:14 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*This function performs the swap operation on a given stack. 
It checks if the stack has at least two elements, and if so, 
it swaps the first two nodes of the stack. The 'sa', 'sb', and 'ss' 
functions call this swap function for stack A, stack B, or both 
stacks respectively, and also handle the output and benchmarking 
of the operations.*/

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_push_swap *ps)
{
	swap(&ps->a);
	if (!ps->count_only)
		write(1, "sa\n", 3);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[SA]++;
	}
}

void	sb(t_push_swap *ps)
{
	swap(&ps->b);
	if (!ps->count_only)
		write(1, "sb\n", 3);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[SB]++;
	}
}

void	ss(t_push_swap *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	if (!ps->count_only)
		write(1, "ss\n", 3);
	if (ps->bench.active || ps->count_only)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[SS]++;
	}
}
