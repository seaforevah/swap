/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 13:34:38 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/25 17:24:18 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mistakes(int *arr, int size, int *total_pairs)
{
	int	i;
	int	j;
	int	mistakes;

	mistakes = 0;
	*total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			*total_pairs++;
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
	int	*arr;
	int	size;
	int	mistakes;
	int	total_pairs;

	size = stack_size(stack);
	arr = stack_to_array(stack, size);
	mistakes = count_mistakes(arr, size, &total_pairs);
	free(arr);
	return (((double)mistakes) / total_pairs);
}
