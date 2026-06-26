/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:28:46 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/09 16:26:45 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_push_swap *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
