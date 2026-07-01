/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:36:11 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/30 20:13:49 by crmatas-         ###   ########.fr       */
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
	if (!ps->b)
		return ;
	push(&ps->a, &ps->b);
	write(1, "pa\n", 3);
	ps->size_a++;
	ps->size_b--;
	if (ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[PA]++;
	}
}

void	pb(t_push_swap *ps)
{
	if (!ps->a)
		return ;
	push(&ps->b, &ps->a);
	write(1, "pb\n", 3);
	ps->size_b++;
	ps->size_a--;
	if (ps->bench.active)
	{
		ps->bench.total_ops++;
		ps->bench.op_counts[PB]++;
	}
}
