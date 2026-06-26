/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dplcte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:32:06 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/03 22:53:00 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dplcte(t_node *stack, int value)
{
	while (stack)
	{
		if (stack -> value == value)
			return (1);
		stack = stack -> next;
	}
	return (0);
}
