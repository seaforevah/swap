/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:27:01 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/25 17:34:27 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function sorts a stack adaptively based on
its disorder level.*/

void	sort_adaptive(t_push_swap *ps)
{
	double	disorder;

	disorder = compute_disorder(ps->a);
	if (disorder < 0.2)
		sort_simple(ps);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(ps);
	else
		radix_algorithm(ps);
}
