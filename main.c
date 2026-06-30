/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:00:06 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/30 21:27:18 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_strategy(t_push_swap *ps)
{
	if (ps->strategy == SIMPLE)
		sort_simple(ps);
	else if (ps->strategy == MEDIUM)
		chunk_sort_algorithm(ps);
	else if (ps->strategy == COMPLEX)
		radix_algorithm(ps);
	else
		sort_adaptive(ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	double		disorder;

	if (argc < 2)
		return (0);
	init_push_swap(&ps);
	parse_args(&ps, argc, argv);
	ps.size_a = stack_size(ps.a);
	normalize_stack(&ps);
	disorder = compute_disorder(ps.a);
	if (!is_sorted(ps.a))
		execute_strategy(&ps);
	if (ps.count_only)
		{
			ft_putnbr_fd(ps.bench.total_ops, 1);
			ft_putchar_fd( '\n', 1);
		}
	else if (ps.bench.active)
		print_benchmark_report(&ps, disorder);
	free_stack(ps.a);
	free_stack(ps.b);
	return (0);
}
