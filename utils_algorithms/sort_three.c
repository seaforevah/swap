/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:20:51 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/25 17:34:14 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This function sorts three elements in stack A using 
//the minimum number of operations.

void	sort_three(t_push_swap *ps)
{
	int	top;
	int	mid;
	int	bot;

	top = ps->a->value;
	mid = ps->a->next->value;
	bot = ps->a->next->next->value;
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
