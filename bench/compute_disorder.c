/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 13:34:38 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/29 23:41:14 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mistakes(int *arr, int size)
{
	int	i;
	int	j;
	int	mistakes;

	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

double	compute_disorder(t_node *stack)
{
	int		*arr;
	int		size;
	int		mistakes;
	double	max_mistakes;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	arr = stack_to_array(stack, size);
	if (!arr)
		return (0.0);
	mistakes = count_mistakes(arr, size);
	free(arr);
	max_mistakes = (double)(size * (size - 1)) / 2.0;
	if (max_mistakes == 0.0)
		return (0.0);
	return ((double)mistakes / max_mistakes);
}
