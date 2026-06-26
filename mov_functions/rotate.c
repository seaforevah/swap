/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:56:33 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/25 17:30:29 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*This function performs the rotate operation on a given stack. 
It checks if the stack has at least two elements, and if so, 
it moves the first element to the end of the stack. The 'ra', 'rb', and 'rr' 
functions call this rotate function for stack A, stack B, or both 
stacks respectively, and also handle the output and benchmarking 
of the operations.*/

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_push_swap *ps)
{
	rotate(&ps->a);
	write (1, "ra\n", 3);
	if (ps->bench && ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RA]++;
	}
}

void	rb(t_push_swap *ps)
{
	rotate(&ps->b);
	write(1, "rb\n", 3);
	if (ps->bench && ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RB]++;
	}
}

void	rr(t_push_swap *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	write(1, "rr\n", 3);
	if (ps->bench && ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[RR]++;
	}
}
