/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 00:31:39 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/10 15:57:39 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_nbr(t_node **stack, int value)
{
	if (is_dplcte(*stack, value))
		return (0);
	add_back(stack, new_node(value));
	return (1);
}
