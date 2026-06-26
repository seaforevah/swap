/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 22:43:55 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/25 17:34:37 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Thhis function finds the minimum value in stack A, rotates
the stack to bring that minimum value to the top, and then pushes it
to stack B. It uses the 'ra' (rotate A) and 'rra' (reverse rotate A)
operations to move the minimum value to the top of stack A before
performing the push operation.*/

void	push_min_to_b(t_push_swap *ps)
{
	t_node	*min;
	int		pos;
	int		size;
	int		steps;

	update_position(ps->a);
	min = find_min(ps->a);
	pos = min->pos;
	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		steps = pos;
		while (steps > 0)
		{
			ra(ps);
			steps--;
		}
	}
	else
	{
		steps = size - pos;
		while (steps-- > 0)
			rra(ps);
	}
	pb(ps);
}
/*This function implements the simple sorting algorithm, slection sort.
It repeatedly pushes the minimum value from stack A to stack B until only
three elements remain in stack A. Then, it sorts the three elements in
stack A using the sort_three function. Finally, it pushes all elements
back from stack B to stack A, resulting in a sorted stack A.*/

void	sort_simple(t_push_swap *ps)
{
	ps->bench.strategy = "Simple / Selection Sort";
	ps->bench.complexity = "O(n^2)";
	while (stack_size(ps->a) > 3)
		push_min_to_b(ps);
	sort_three(ps);
	while (stack_size(ps->b) > 0)
		pa(ps);
}
