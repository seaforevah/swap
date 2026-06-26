/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to _top_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:02:00 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/25 12:20:15 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top_a(t_push_swap *ps, int pos)
{
	int	size;
	int	moves;

	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
	}
	else
	{
		moves = size - pos;
		while (moves > 0)
		{
			rra(ps);
			moves--;
		}
	}
}
