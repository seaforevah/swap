/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:27:41 by maaros-f          #+#    #+#             */
/*   Updated: 2026/07/01 20:31:05 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_max_pos(t_node *stack)
{
	t_node	*max;
	int		pos;
	int		max_pos;

	if (!stack)
		return (-1);
	max = find_max(stack);
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack == max)
		{
			max_pos = pos;
			break ;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

void	bring_to_top_b(t_push_swap *ps, int pos)
{
	int	size;
	int	moves;

	size = stack_size(ps->b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(ps);
			pos--;
		}
	}
	else
	{
		moves = size - pos;
		while (moves > 0)
		{
			rrb(ps);
			moves--;
		}
	}
}

void	push_chunks_to_b(t_push_swap *ps, int chunk_size)
{
	int	start;
	int	end;
	int	pos;

	start = 0;
	end = chunk_size - 1;
	while (stack_size(ps->a) > 0)
	{
		while (find_first_chunk_pos(ps->a, start, end, &pos))
		{
			bring_to_top_a(ps, pos);
			pb(ps);
		}
		start += chunk_size;
		end += chunk_size;
	}
}

void	push_back_to_a(t_push_swap *ps)
{
	int	pos;

	while (ps->b)
	{
		pos = find_max_pos(ps->b);
		bring_to_top_b(ps, pos);
		pa(ps);
	}
}
