/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:14:37 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/16 16:23:37 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_selector(t_strategy *ss, char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		*ss = SIMPLE;
	if (!ft_strcmp(arg, "--medium"))
		*ss = MEDIUM;
	if (!ft_strcmp(arg, "--complex"))
		*ss = COMPLEX;
	if (!ft_strcmp(arg, "--adaptive"))
		*ss = ADAPTIVE;
}
