*This project has been created as part of the 42 curriculum by moamhouc.*

# PUSH_SWAP

## Description

push_swap is a sorting algorithm project whose goal is to sort a stack of integers using the smallest possible number of operations. The program takes a list of integers as input, stores them in a stack (stack A), and sorts them in ascending order by manipulating two stacks (A and B) using a restricted set of operations. Any direct access to elements is forbidden, which forces the implementation of efficient sorting strategies rather than traditional sorting algorithms.
The challenge of the project lies in choosing and optimizing algorithms that minimize the number of operations for different input sizes. For small data sets, simple sorting logic is applied, while larger data sets require more advanced techniques such as indexing and chunk-based (butterfly) sorting.
Through this project, i gained a deeper understanding of algorithmic complexity, data structures, and optimization under constraints, while working within strict rules that simulate real-world problem-solving scenarios.

Here is a clear and professional **Instructions** section. It covers everything from the `Makefile` rules to the exact commands needed to verify your performance against the 42 benchmarks.

---

## Instructions

### Compilation

The project includes a `Makefile` that handles compilation with the `-Wall -Wextra -Werror` flags.

* **To compile the mandatory part:**
```bash
make
```
This generates the `push_swap` executable file.

* **To compile the bonus part (Checker):**
```bash
make bonus
```
This generates the `checker` executable file.

* **Cleaning up:**
```bash
make clean
make fclean
make re
```
---

### Execution

#### **Running the Solver**

You need to provide a list of integers as arguments. The numbers can be passed as separate arguments or as a single quoted string.

```bash
./push_swap 2 1 3 6 5 8

./push_swap "2 1 3 6 5 8"
```

#### **Running the Checker (Manual)**

The checker waits for instructions from `stdin`. You type the moves, then press `Ctrl+D` to finish.

```bash
./checker 3 2 1
sa
ra
OK
```

#### **Running Together**

This is the standard way to verify if your algorithm works:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

```
---

#### Benchmarking & Testing

To evaluate the efficiency of the algorithm, you can count the number of instructions generated.

**For 100 random numbers:**

```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```
* *Score 5/5:* Under 700 moves.


**For 500 random numbers:**

```bash
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```
* *Score 5/5:* Under 5500 moves.

---

### Error Handling

The program strictly follows the 42 subject requirements for errors. It will display `Error\n` on `stderr`.

---

## Resources

### Technical References

* **42 School — Push_swap Subject PDF**
  Official project specifications and constraints.

* **Peer discussions**
  General strategy comparisons and edge-case reasoning.

* **Stack & Sorting Algorithm References**
  * Stack operation theory (push, swap, rotate, reverse rotate).
  * Simple sorting strategies for small datasets.
  * Chunk-based (butterfly) sorting strategies for large datasets.

### AI Usage Disclosure

* High-level algorithm understanding

* Clarifying the logic behind chunk-based (“butterfly”) sorting.

* Understanding optimal strategies for small input sizes (≤ 5).

---

## Linear flow diagram

```c
main
  ↓
verify_args
  ↓
str_checker (split argv strings, check chars / empty)
  ├─ invalid token / format → ft_errors (error path, exit)
  ↓
ft_atoi (convert to int, range check)
  ├─ overflow / invalid number → ft_errors (error path, exit)
  ↓
ft_duplicated (check all numbers are unique)
  ├─ duplicate found → ft_errors (error path, exit)
  ↓
convert_to_int (store validated ints in array)
  ↓
count_size (compute total N)
  ↓
transfer_to_stack
  ├─ build stack_a from array
  └─ init empty stack_b
  ↓
sorted ? (check if stack_a already ordered)
  ├─ yes → early exit (normal path ends, no moves)
  └─ no
       ↓
     filling_arr (copy stack_a values to temp array)
       ↓
     sorted_arr (sort temp array)
       ↓
     indixing_stack (map values in stack_a to indexes 0..N-1)
       ↓
     sort (dispatch by N)
       ├─ N == 2
       │    ↓
       │  two_sort
       │    (apply sa if needed; then done)
       │
       ├─ N == 3
       │    ↓
       │  three_sort
       │    (sa / ra / rra combinations; then done)
       │
       ├─ N == 4 or N == 5
       │    ↓
       │  four_five_sort
       │    - push smallest indexes to stack_b (pb)
       │    - three_sort on remaining in stack_a
       │    - push back to stack_a (pa)
       │    (small-input path ends here)
       │
       └─ N > 5
            ↓
          main_sort (butterfly, phase 1)
            - size_range (current index window / chunk)
            - while stack_a not empty:
                • if top index in current window → pb to stack_b
                • else → rotate stack_a (ra / rra) to reach window
            ↓
          main_sort_part2 (phase 2, rebuild stack_a)
            - while stack_b not empty:
                • max_index (largest index in stack_b)
                • max_index_spot (position of that index)
                • choose rb / rrb to bring it to top with minimal moves
                • pa to push it back to stack_a
            ↓
          final sorted stack_a (normal path end)
```

---

### Bonus: checker flow

```c
checker_main
  ↓
verify_args
  ↓
str_checker → ft_atoi → ft_duplicated
  ├─ any validation error → ft_errors (error path, exit)
  ↓
convert_to_int → count_size → transfer_to_stack (build stack_a, empty stack_b)
  ↓
(read and execute operations  with get_next_line(stdin) line-by-line on stacks)
  ├─ invalid / unknown operation → ft_errors (error path, exit)
  ↓
checker (validate final state)
  ├─ stack_a sorted & stack_b empty → print "OK"
  └─ otherwise                    → print "KO"
```

---
