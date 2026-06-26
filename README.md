_This project has been created as part of the 42 curriculum by crmatas-, maaros-f._


## Data Structures

### `t_strategy`

Enumeration that defines the available sorting strategies used by the program.

```c
typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;
```

| Strategy | Description |
|-----------|-------------|
| `SIMPLE` | Used for small input sets. |
| `MEDIUM` | Optimized for medium-sized datasets. |
| `COMPLEX` | Intended for large or more demanding cases. |
| `ADAPTIVE` | Selects the most suitable behavior based on the current state of the stacks. |

---

### `t_node`

Represents a single element in a stack. The stacks are implemented as singly linked lists.

```c
typedef struct s_node
{
	int	index;
	int	value;
	int	cost;
	int	pos;
	struct s_node	*next;
}	t_node;
```

| Field | Description |
|---------|-------------|
| `index` | Normalized rank of the value within the input set. |
| `value` | Original integer value. |
| `cost` | Estimated number of operations required to move the node. |
| `pos` | Current position inside the stack. |
| `next` | Pointer to the next node. |

---
### `t_node`
 
Represents a single element in a stack. The stacks are implemented as singly linked lists.
 
```c
typedef struct s_node
{
	int	index;
	int	value;
	int	cost;
	int	pos;
	struct s_node	*next;
}	t_node;
```
 
| Field | Description |
|---------|-------------|
| `index` | Normalized rank of the value within the input set. |
| `value` | Original integer value. |
| `cost` | Estimated number of operations required to move the node. |
| `pos` | Current position inside the stack. |
| `next` | Pointer to the next node. |
 
---
 
### `t_op_counts`
 
Enumeration that maps each Push_swap instruction to a fixed index (0–10) inside the benchmark's operation array, avoiding magic numbers when counting operations.
 
```c
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
} t_op_counts;
```
 
---
 
### `t_bench`
 
Holds every piece of information needed by the optional `--bench` mode.
 
```c
typedef struct s_bench
{
    int     active;
    char    *strategy;
    char    *complexity;
    int     total_ops;
    int     op_counts[11];
}   t_bench;
```
 
| Field | Description |
|---------|-------------|
| `active` | `1` if `--bench` was passed as an argument, `0` otherwise. |
| `strategy` | Human-readable name of the strategy that was actually used (e.g. `"Adaptive"`). |
| `complexity` | Theoretical complexity class of that strategy as text (e.g. `"O(n log n)"`). |
| `total_ops` | Total number of operations generated while sorting. |
| `op_counts` | Per-operation counters, indexed with `t_op_counts` (`op_counts[SA]`, `op_counts[PB]`...). |
 
Every movement function (`sa`, `pb`, `ra`...) receives a `t_bench *` and increments `total_ops` and the matching `op_counts` entry only when `bench->active` is true, so benchmarking never interferes with the normal stdout operation stream read by the checker.
 
---

### `t_push_swap`
 
Main structure that stores both stacks and their associated metadata.
 
```c
typedef struct s_push_swap
{
	t_node		*a;
	t_node		*b;
	int			size_a;
	int			size_b;
	t_strategy	strategy;
	t_bench		bench;
	int			has_strategy;
}	t_push_swap;
```
 
| Field | Description |
|---------|-------------|
| `a` | Primary stack. |
| `b` | Auxiliary stack. |
| `size_a` | Number of elements in stack A. |
| `size_b` | Number of elements in stack B. |
| `strategy` | Current sorting strategy. |
| `bench` | Benchmark data, populated and printed only when `--bench` is active. |
| `has_strategy` | `1` once a strategy flag has been read from the arguments, `0` otherwise. Used to detect and reject duplicate strategy flags. |
 
This structure acts as the central context of the program and is passed throughout the sorting process to keep track of stack states and algorithm decisions.

---

## Input Parsing

The parser accepts numbers either as individual arguments:

```bash
./push_swap 3 2 1
```

or as a quoted string:

```bash
./push_swap "3 2 1"
```

### Validation Process

For every input value the parser performs the following checks:

1. The string must contain a valid integer representation.
2. The value must fit within the `int` range (`INT_MIN` to `INT_MAX`).
3. Duplicate values are rejected during node insertion (`add_nbr()`).
4. Any invalid input triggers the error handler and terminates execution.

### Strategy Selection

An optional strategy flag may be provided as the first argument:

```bash
./push_swap --adaptive 3 2 1
```

When detected, the selected strategy is stored in the main context before parsing the remaining values.

### Parsing Flow

```text
argv
  │
  ▼
parse_args()
  │
  ├── strategy detection
  │
  └── split()
        │
        ▼
    parse_content()
        │
        ├── numeric validation
        ├── range validation
        ├── duplicate validation
        └── add_nbr()
```
## Stack Operations
 
The program manipulates stacks `a` and `b` using exactly 11 operations, as defined by the subject. Every operation prints its name to standard output and, when `--bench` is active, increments its corresponding counter in `t_bench`.
 
| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements at the top of `a`. Does nothing with 0 or 1 elements. |
| `sb` | Swap the first two elements at the top of `b`. Does nothing with 0 or 1 elements. |
| `ss` | Equivalent to `sa` and `sb` at the same time. |
| `pa` | Take the top element of `b` and push it onto the top of `a`. Does nothing if `b` is empty. |
| `pb` | Take the top element of `a` and push it onto the top of `b`. Does nothing if `a` is empty. |
| `ra` | Rotate `a`: the top element becomes the bottom one. |
| `rb` | Rotate `b`: the top element becomes the bottom one. |
| `rr` | Equivalent to `ra` and `rb` at the same time. |
| `rra` | Reverse rotate `a`: the bottom element becomes the top one. |
| `rrb` | Reverse rotate `b`: the bottom element becomes the top one. |
| `rrr` | Equivalent to `rra` and `rrb` at the same time. |
 
### Implementation details
 
**Files:** `swap.c`, `push.c`, `rotate.c`, `reverse_rotate.c`
 
- `swap`, `push`, `rotate` and `rev_rotate` contain the actual pointer logic for each movement and operate on a single stack (`t_node **`) at a time.
- `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb` are thin wrappers around those internal functions: they perform the movement, print the operation name to `stdout`, and update the benchmark counters.
- The double operations (`ss`, `rr`, `rrr`) simply call their two single counterparts back to back, printing only the combined name once.
Every operation receives a `t_bench *bench` pointer so it can record itself in `bench->op_counts[]` (indexed through the `t_op_counts` enum) whenever benchmarking is active, without affecting the normal stdout output used by the checker.
 
---
## Sorting Algorithms
 
### SIMPLE — O(n²)
 
The `SIMPLE` strategy is a **selection sort adaptation**, designed for small input sets where a quadratic approach remains fast enough.
 
**Files:** `sort_simple.c`
 
**Functions:**
 
```c
void	push_min_to_b(t_push_swap *ps);
void	sort_three(t_node **stack_a, t_bench *bench);
void	sort_simple(t_push_swap *ps);
```
 
#### How it works
 
1. While stack `a` has more than 3 elements, repeatedly call `push_min_to_b`:
   - Find the minimum value currently in `a` using `find_min`.
   - Compute its position with `update_position` and `stack_size`.
   - Rotate it to the top using the cheapest direction: `ra` if the element is in the first half of the stack, `rra` otherwise.
   - Push it onto `b` with `pb`.
2. Once `a` holds exactly 3 elements, sort them directly with `sort_three`.
3. Push every remaining element from `b` back into `a` with `pa`.
#### Why no extra rotation on `b` is needed
 
Each value pushed onto `b` is, by construction, **larger** than every value pushed before it (because we always extract the current minimum of what remains in `a`). This means `b` naturally ends up ordered from largest (top) to smallest (bottom). When elements are then pushed back into `a` one by one with `pa`, they arrive in ascending order at the top of `a`, leaving the whole stack correctly sorted without any additional rotation of `b`.
 
#### Complexity (in the Push_swap operation model)
 
For each of the `n` elements moved into `b`, the algorithm scans the whole remaining stack once to find the minimum (`find_min`, `stack_size`, `update_position` are all O(n)). Repeating this `n` times gives **O(n²)** operations in total, which matches the complexity class required for the `SIMPLE` strategy.
 
### Disorder metric
 
**Files:** `compute_disorder.c`
 
```c
double	compute_disorder(t_node *stack);
```
 
The subject requires a mandatory metric, computed **before any move**, that expresses how far stack `a` is from being sorted. A value of `0` means the stack is already sorted; a value of `1` means it is in the worst possible order.
 
#### How it works
 
1. The stack is converted into a plain integer array with `stack_to_array`, since the disorder formula compares elements by index.
2. Every possible pair `(i, j)` with `i < j` is examined exactly once.
3. Each pair is counted in `total_pairs`. If the earlier element is greater than the later one (`arr[i] > arr[j]`), it is also counted as a `mistake`.
4. The result is `mistakes / total_pairs`, cast to `double` so the division keeps its decimal precision instead of being truncated.
This follows the exact formula given by the subject (VI.3.2), adapted only to work on an array instead of an abstract indexable collection.
 
### ADAPTIVE
 
**Files:** `sort_adaptive.c`
 
```c
void	sort_adaptive(t_push_swap *ps);
```
 
`ADAPTIVE` is not a sorting algorithm on its own: it is a **selector** that measures the initial disorder of stack `a` and delegates the actual sorting to one of the other three strategies, following the thresholds required by the subject.
 
#### Thresholds and rationale
 
| Disorder | Strategy used | Theoretical complexity |
|---|---|---|
| `disorder < 0.2` | `sort_simple` | O(n²) |
| `0.2 ≤ disorder < 0.5` | `sort_medium` | O(n√n) |
| `disorder ≥ 0.5` | `radix_algorithm` | O(n log n) |
 
These thresholds match the regimes imposed by the subject itself (VI.3.3, point 4). The reasoning behind them:
 
- **Low disorder (< 0.2):** the stack is already close to sorted, so the overhead of building chunks or running a radix pass would cost more operations than it saves. A direct O(n²) selection sort finds and fixes the few remaining mistakes with minimal extra cost.
- **Medium disorder (0.2–0.5):** the stack is partially shuffled. Splitting the values into roughly `√n` chunks groups nearby values together, letting the algorithm sort large ranges of the stack at once instead of moving one element at a time.
- **High disorder (≥ 0.5):** the stack is heavily shuffled, close to a worst-case random order. At this point the O(n log n) radix-based strategy is the only one that keeps the number of operations bounded as `n` grows, even though it is more expensive to set up than the other two.
#### Complexity and space argument
 
`compute_disorder` itself runs in O(n²) (it compares every pair of elements), but this cost is paid only **once**, before any sorting decision, and is independent of which strategy is later chosen. The complexity class claimed for each branch (`O(n²)`, `O(n√n)`, `O(n log n)`) refers to the number of Push_swap operations generated by the strategy that `sort_adaptive` delegates to, not to the cost of measuring disorder itself. In terms of space, `compute_disorder` only allocates one temporary integer array of size `n` (freed immediately after use), so its memory cost is O(n) and does not accumulate across calls.

# Resources
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
https://www.manning.com/books/grokking-algorithms?source=post
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a