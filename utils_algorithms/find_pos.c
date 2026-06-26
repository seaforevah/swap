/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 21:50:56 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/16 21:52:32 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_pos(t_node *stack, int pos)
{
	while (stack)
	{
		if (stack->pos == pos)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
