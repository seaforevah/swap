/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:20:51 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/28 23:24:49 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This function sorts three elements in stack A using 
//the minimum number of operations.

static void	sort_two(t_push_swap *ps)
{
	if (ps->a->value > ps->a->next->value)
		sa(ps);
}

static void	order_three(t_push_swap *ps, int top, int mid, int bot)
{
	if (top < bot && bot < mid)
	{
		sa(ps);
		ra(ps);
	}
	else if (mid < top && top < bot)
		sa(ps);
	else if (mid < bot && bot < top)
		ra(ps);
	else if (bot < top && top < mid)
		rra(ps);
	else if (bot < mid && mid < top)
	{
		sa(ps);
		rra(ps);
	}
}

void	sort_three(t_push_swap *ps)
{
	if (!ps->a || !ps->a->next)
		return ;
	if (!ps->a->next->next)
	{
		sort_two(ps);
		return ;
	}
	order_three(ps, ps->a->value, ps->a->next->value, ps->a->next->next->value);
}
