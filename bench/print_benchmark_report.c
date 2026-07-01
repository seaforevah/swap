/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark_report.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmatas- <crmatas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:09:25 by maaros-f          #+#    #+#             */
/*   Updated: 2026/06/29 21:46:07 by crmatas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder, int fd)
{
	double	percent;
	int		int_part;
	int		dec_part;

	percent = disorder * 100;
	int_part = (int)percent;
	dec_part = (int)((percent - int_part) * 100);
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(int_part, fd);
	ft_putstr_fd(".", fd);
	print_two_digits(dec_part, fd);
	ft_putstr_fd("%\n", fd);
}

void	print_strategy_info(t_push_swap *ps, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	ft_putstr_fd(ps->bench.strategy, fd);
	ft_putstr_fd(" / ", fd);
	ft_putstr_fd(ps->bench.complexity, fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(ps->bench.total_ops, fd);
	ft_putstr_fd("\n", fd);
}

void	print_op_counts(t_push_swap *ps, int fd)
{
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[SA], fd);
	ft_putstr_fd("  sb: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[SB], fd);
	ft_putstr_fd("  ss: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[SS], fd);
	ft_putstr_fd("  pa: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[PA], fd);
	ft_putstr_fd("  pb: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[PB], fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RA], fd);
	ft_putstr_fd("  rb: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RB], fd);
	ft_putstr_fd("  rr: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RR], fd);
	ft_putstr_fd("  rra: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RRA], fd);
	ft_putstr_fd("  rrb: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RRB], fd);
	ft_putstr_fd("  rrr: ", fd);
	ft_putnbr_fd(ps->bench.op_counts[RRR], fd);
	ft_putstr_fd("\n", fd);
}

void	print_benchmark_report(t_push_swap *ps, double disorder)
{
	print_disorder(disorder, 2);
	print_strategy_info(ps, 2);
	print_op_counts(ps, 2);
}
