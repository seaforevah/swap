/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:36:11 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/27 18:23:21 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*This function performs the push operation from one stack to another. 
It checks if the source stack has elements, and if so, 
it moves the first element from the source stack to the destination 
stack. The 'pa' and 'pb' 
functions call this push function to move elements between stacks, and 
also handle the output and benchmarking of the operations.*/

void	push(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_push_swap *ps)
{
	push(&ps->a, &ps->b);
	write(1, "pa\n", 3);
	if (ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[PA]++;
	}
}

void	pb(t_push_swap *ps)
{
	push(&ps->b, &ps->a);
	write(1, "pb\n", 3);
	if (ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[PB]++;
	}
}
