/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:52:32 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/26 23:48:16 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_push_swap *ps)
{
	int	*arr;
	int	*sorted;

	arr = stack_to_array(ps->a, ps->size_a);
	if (!arr)
		return ;
	sorted = copy_array(arr, ps->size_a);
	if (!sorted)
	{
		free (arr);
		return ;
	}
	sort_array(sorted, ps->size_a);
	assign_index(ps->a, sorted, ps->size_a);
	free (arr),
	free (sorted);
}
