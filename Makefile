# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Source files
SRCS = algorithms/chunk_sort_algorithm.c \
	algorithms/radix_algorithm.c \
	algorithms/sort_adaptive.c \
	algorithms/sort_simple.c \
	error/error.c \
	initialize/init_nodes.c \
	initialize/init_push_swap.c \
	lists/add_back.c \
	lists/add_nbr.c \
	lists/last_node.c \
	lists/new_node.c \
	memory/free_mtx.c \
	memory/free_stack.c \
	utils/ft_atol.c \
	utils/ft_strcmp.c \
	utils/ft_strdup.c \
	utils/ft_substr.c \
	utils/split.c \
	utils/ft_strlen.c \
	utils_algorithms/assign_index.c \
	utils_algorithms/bring_to_top_a.c \
	utils_algorithms/contains_chunk.c \
	utils_algorithms/copy_array.c \
	utils_algorithms/find_first_chunk_pos.c \
	utils_algorithms/find_index.c \
	utils_algorithms/find_max.c \
	utils_algorithms/find_min.c \
	utils_algorithms/find_pos.c \
	utils_algorithms/get_chunks_size.c \
	utils_algorithms/get_max_bits.c \
	utils_algorithms/normalize_stack.c \
	utils_algorithms/sort_array.c \
	utils_algorithms/stack_size.c \
	utils_algorithms/stack_to_array.c \
	utils_algorithms/update_position.c \
	utils_algorithms/utils_chunks.c \
	parse/is_dplcte.c \
	parse/is_sorted.c \
	parse/is_strategy.c \
	parse/parse_args.c \
	parse/strategy_selector.c \
	moves/push.c \
	moves/reverse_rotate.c \
	moves/rotate.c \
	moves/sort_three.c \
	moves/swap.c \
	bench/print_benchmark_report.c \
	bench/compute_disorder.c \
	bench/utils_benchmark.c \
	main.c 

# Archivos objeto
# Take the .c and creates the .o inside a folder called objects
# OBJS = $(SRCS:.c=.o)
OBJDIR = objects
VPATH = $(sort $(dir $(SRCS)))
OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))

# Default rule
all: $(NAME)

# Create the mandatory executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compiles .c a .o
$(OBJDIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -rf $(OBJDIR)

# Clean everything
fclean: clean
	@rm -f $(NAME)

# Recompile everything
re: fclean all

# Prevent conflicts with files of the same name
.PHONY: all clean fclean re