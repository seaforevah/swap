/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaros-f <maaros-f@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:30:49 by crmatas-          #+#    #+#             */
/*   Updated: 2026/06/30 18:14:06 by maaros-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_op_counts
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_op_counts;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

typedef struct s_node
{
	int				index;
	int				value;
	int				pos;
	struct s_node	*next;
}					t_node;

typedef struct s_bench
{
	int				active;
	char			*strategy;
	char			*complexity;
	int				total_ops;
	int				op_counts[11];
}					t_bench;

typedef struct s_push_swap
{
	t_node			*a;
	t_node			*b;
	int				size_a;
	int				size_b;
	t_strategy		strategy;
	t_bench			bench;
	int				count_only;
	int				has_strategy;
}					t_push_swap;

// algorithms
void				chunk_sort_algorithm(t_push_swap *ps);
void				radix_algorithm(t_push_swap *ps);
void				push_min_to_b(t_push_swap *ps);
void				sort_simple(t_push_swap *ps);
void				sort_adaptive(t_push_swap *ps);

// benchmark
void				print_benchmark_report(t_push_swap *ps, double disorder);
// error
void				error(t_push_swap *ps);
// initialize
void				init_push_swap(t_push_swap *ps);
void				init_nodes(t_push_swap *ps);
// lists
void				add_back(t_node **stack, t_node *new);
int					add_nbr(t_node **stack, int value);
t_node				*last_node(t_node *stack);
t_node				*new_node(int value);
// memory
void				free_mtx(char **mtx);
void				free_stack(t_node *stack);
// parse
int					is_dplcte(t_node *stack, int value);
int					is_sorted(t_node *stack);
int					is_strategy(char *arg);
int					parse_args(t_push_swap *ps, int argc, char **argv);
void				strategy_selector(t_strategy *ss, char *arg);
// utils
char				*ft_strdup(const char *s);
char				**split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
long				ft_atol(const char *nptr);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);

// utils_algorithms
void				assign_index(t_node *stack, int *sorted, int size);
void				bring_to_top_a(t_push_swap *ps, int pos);
int					contains_chunk(t_node *a, int start, int end);
int					*copy_array(int *arr, int size);
int					find_first_chunk_pos(t_node *a, int start, int end,
						int *pos_out);
int					find_index(int value, int *sorted, int size);
t_node				*find_max(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_pos(t_node *stack, int pos);
int					get_chunk_size(int size);
int					get_max_bits(t_push_swap *ps);
void				normalize_stack(t_push_swap *ps);
void				sort_array(int *arr, int size);
int					stack_size(t_node *stack);
int					*stack_to_array(t_node *stack, int size);
void				update_position(t_node *stack);
void				sort_three(t_push_swap *ps);
double				compute_disorder(t_node *stack);

// mov_functions
void				swap(t_node **stack);
void				sa(t_push_swap *ps);
void				sb(t_push_swap *ps);
void				ss(t_push_swap *ps);

void				push(t_node **dst, t_node **src);
void				pa(t_push_swap *ps);
void				pb(t_push_swap *ps);

void				rotate(t_node **stack);
void				ra(t_push_swap *ps);
void				rb(t_push_swap *ps);
void				rr(t_push_swap *ps);

void				rev_rotate(t_node **stack);
void				rra(t_push_swap *ps);
void				rrb(t_push_swap *ps);
void				rrr(t_push_swap *ps);

// Utils benchmark
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);

#endif