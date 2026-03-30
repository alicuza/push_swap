_This project has been created as part of the 42 curriculum by sancuta._

# push_swap

## Description

Push Swap sorts numbers on a stack with a limited palette of operations.

The program receives a list of integers as **stack A** (top = first number)
and must output a minimal-ish sequence of instructions (one per line) that
sorts A in ascending order, using an auxiliary **stack B**.

This implementation:
- validates input (integers, range, duplicates)
- early-exits on already-sorted input
- uses a small dedicated sorter for few inputs
- uses a rank-based radix sort for larger inputs

---

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
  - [Compilation](#compilation)
  - [Usage](#usage)
  - [Allowed Operations](#allowed-operations)
- [Known Limitations](#known-limitations)
- [Algorithm and Data Structure](#algorithm-and-data-structure)
  - [Architecture Overview](#architecture-overview)
  - [Core Data Structure](#core-data-structure)
  - [Parsing](#parsing)
  - [Sorting Strategy](#sorting-strategy)
    - [Mini sort (2–5 numbers)](#mini-sort-25-numbers)
    - [Radix sort (6+ numbers)](#radix-sort-6-numbers)
  - [Error Handling and Cleanup](#error-handling-and-cleanup)
- [Resources](#resources)
  - [Documentation and References](#documentation-and-references)
  - [AI Usage](#ai-usage)

---

## Instructions

### Compilation

- `make` or `make all` — compiles `pipex`;
- `make clean` — removes object and dependency files;
- `make fclean` — additionally removes the binary and libs;
- `make re` — recompiles the entire project from scratch;
- `make debug` — compiles with the `-g` flag for debugging;

**Dependencies:**
- libft (bundled)

### Usage

```bash
./push_swap 3 2 1
./push_swap 0 -1 42 2147483647
```

Output is a list of operations separated by `\n`, for example:

```bash
./push_swap -1 5 2 0
ra
sa
pa
```

If the input is already sorted (or no work is needed), the program prints
nothing and exits successfully.

### Allowed Operations

**Swap**
- `sa` — swap the first 2 elements at the top of A
- `sb` — swap the first 2 elements at the top of B
- `ss` — `sa` and `sb` at the same time

**Push**
- `pa` — push the top element of B onto A
- `pb` — push the top element of A onto B

**Rotate**
- `ra` — shift up all elements of A by 1 (top becomes bottom)
- `rb` — shift up all elements of B by 1
- `rr` — `ra` and `rb` at the same time

**Reverse Rotate**
- `rra` — shift down all elements of A by 1 (bottom becomes top)
- `rrb` — shift down all elements of B by 1
- `rrr` — `rra` and `rrb` at the same time

---

## Known Limitations

- Not optimized for minimum instruction count beyond the intended project targets.
- Does not support numbers as arguments in a single string: `./push_swap "3 2 1"
  does not work.
- The large-input strategy is radix-based (great for reliability; but slower than
  greedier approaches and not fit to sort under 6 elements).

---

## Algorithm and Data Structure

### Architecture Overview

1. Initialize an environment (`t_env`) and allocate nodes for stacks.
2. Parse and validate `argv` into stack A.
3. If already sorted: exit cleanly.
4. Assign ranks to values.
5. Choose sorting strategy:
   - for `argc < 6` (2–5 numbers): `mini_sort`
   - otherwise: `radix_sort`
6. Print operations if they are actually executed (using `ft_printf`).

### Core Data Structure

The program stores both stacks in a single node array and tracks the two "heads":

Index `0` is a special, **zii sentinel node** that acts as a
self-referential `nil` value. (zii stands for "zero is initialization")

This means:
- an empty stack is represented by `head == 0`
- node `0` is never a real element
- operations can rely on a stable "nil object" instead of `NULL` pointers

```c
/*
   Index 0 is the sentinel:
   node[0].next == 0
   node[0].prev == 0
 */

typedef struct s_node
{
	int			nbr;
	int			rank;
	t_stack_idx	next;
	t_stack_idx	prev;
}	t_node;

typedef struct s_env
{
	t_node		*node;
	t_stack_idx	head_a;
	t_stack_idx	head_b;
}	t_env;
```

Because `0` is a valid array index, it also serves as a convenient boundary
marker for list traversal and simplifies edge cases like pushing/popping the
last element of a stack.

Each operation mutates the linked structure (via indices/pointers) and prints
the corresponding instruction when it actually modifies the stack.

### Parsing

Parsing is strict:
- accepts only valid integer strings
- checks for overflow / out-of-range
- rejects duplicates
- on error prints `Error\n` to `stderr` and exits

### Sorting Strategy

#### Mini sort (2–5 numbers)

Small inputs are being handled simply, depending on the count:

- `len == 2`: swap if needed
- `len == 3`: dedicated 3-element sorter
- `len > 3`: repeatedly rotate the minimum to the top,
			 `pb` it to B until 3 remain, sort 3,
			 then `pa` everything back

#### Radix sort (6+ numbers)

For larger inputs, values are first mapped to ranks $0..n-1$ (coordinate
compression), so bitwise radix sorting becomes straightforward.

The algorithm then iterates over the bits (LSB $\rightarrow$ MSB) and
stable-partitions the elements between stacks A and B based on the current bit.

**Time complexity:** $\mathcal{O}(n \log n)$  
(where $\log n$ is the number of bits needed to represent $n$ ranks)

**Space complexity:** $\mathcal{O}(n)$  
(node storage; the algorithm itself uses constant extra bookkeeping)

### Error Handling and Cleanup

All exits funnel into `cleanup()`, which:
- frees allocated memory
- prints an error message when appropriate
- exits with the given status

---

## Resources

### Documentation and References

- [LIS](https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html)
- [Big O Notation and Time Complexity](https://en.wikipedia.org/wiki/Time_complexity)
- [Radix Sort](https://notes.devnyxie.com/0-Notes/c/radix)
- [Bitwise Radix Sort](https://en.wikipedia.org/wiki/Radix_sort#In-place_MSD_radix_sort_implementations)

### AI Usage

AI tools were used mainly for interactive rubber ducking, and searching for information.
