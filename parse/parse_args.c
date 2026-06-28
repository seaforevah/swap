/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:50:17 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/27 18:34:42 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*
 * Checks whether a string represents a valid integer.
 * Accepts an optional leading '+' or '-'.
 * Returns 1 if valid, 0 otherwise.
 */

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*
 * Validates and inserts every number from the split matrix.
 *
 * Checks:
 *   - Numeric format
 *   - Integer overflow/underflow
 *   - Duplicate values (inside add_nbr)
 *
 * On failure the program exits through error().
 */

static int	parse_content(char **mtx, t_push_swap *ps)
{
	int		j;
	long	n;

	j = 0;
	while (mtx[j])
	{
		if (!is_num(mtx[j]))
			error(ps);
		n = ft_atol(mtx[j]);
		if (n > INT_MAX || n < INT_MIN)
			error(ps);
		if (!add_nbr(&ps->a, (int)n))
			error(ps);
		j++;
	}
	return (1);
}

/*
 * Parses 1 arg at a time.
 *
 * checks for flags and stores with booleans in case they repeat.
 * it is stored in ps->strategy and skipped.
 *
 * Each remaining argument is split by spaces to support:
 *   ./push_swap "3 2 1"
 * as well as:
 *   ./push_swap 3 2 1
 */

static void	parse_arg(t_push_swap *ps, char *argv)
{
	char	**mtx;

	if (is_strategy(argv))
	{
		if (ps->has_strategy)
			error(ps);
		ps->has_strategy = 1;
		strategy_selector(&ps->strategy, argv);
	}
	else if (ft_strcmp(argv, "--bench") == 0)
		ps->bench.active = 1;
	else
	{
		mtx = split(argv, ' ');
		if (!mtx)
			error(ps);
		if (!parse_content(mtx, ps))
		{
			free_mtx(mtx);
			error (ps);
		}
		free_mtx(mtx);
	}
	return ;
}

int	parse_args(t_push_swap *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_arg(ps, argv[i]);
		i++;
	}
	return (1);
}
