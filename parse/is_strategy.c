/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:59:38 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/10 15:58:43 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strategy(char *arg)
{
	return (!ft_strcmp(arg, "--simple")
		|| !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--complex")
		|| !ft_strcmp(arg, "--adaptive"));
}
