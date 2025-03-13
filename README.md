# Push_swap

Push_swap is a sorting algorithm project from the 42 school curriculum. The goal of the project is to sort a stack of integers using a limited set of operations and an auxiliary stack, while aiming for the most efficient solution in terms of the number of operations.

## Table of Contents

- [Overview](#overview)
- [Rules](#rules)
- [Operations](#operations)
- [Objectives](#objectives)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Evaluation](#evaluation)
- [Resources](#resources)

---

## Overview

The **Push_swap** project challenges you to sort a stack of integers using a minimal number of operations. The project is designed to test your algorithmic thinking, problem-solving skills, and ability to write efficient and optimized code.

The program generates a sequence of operations to sort the stack.

---

## Rules

- You are given two stacks: **A** (initially filled with integers) and **B** (empty at the start).
- Your goal is to sort stack **A** in ascending order using stack **B** as an auxiliary stack.
- You can only use a predefined set of operations (see below).
- The program must output the sequence of operations required to sort the stack.

---

## Operations

The allowed operations are:

- **Swap**:
  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Perform `sa` and `sb` simultaneously.

- **Push**:
  - `pa`: Push the top element of stack B onto stack A.
  - `pb`: Push the top element of stack A onto stack B.

- **Rotate**:
  - `ra`: Rotate stack A upwards (first element becomes the last).
  - `rb`: Rotate stack B upwards.
  - `rr`: Perform `ra` and `rb` simultaneously.

- **Reverse Rotate**:
  - `rra`: Reverse rotate stack A (last element becomes the first).
  - `rrb`: Reverse rotate stack B.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

---

## Objectives

- Write a program that generates the most efficient sequence of operations to sort the stack.
- Optimize your algorithm to handle large stacks efficiently.

---

## Usage

### Compilation

To compile the project, use the provided `Makefile`:

```bash
make
```

This will generate the `push_swap` executable.

### Running the Program

Run the program with a list of integers as arguments:

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 4 3 2 1
```

The program will output the sequence of operations required to sort the stack.

---

## Algorithm

For this project, I implemented the **Radix Sort** algorithm, which is a non-comparative sorting algorithm. It is particularly efficient for sorting integers and works well within the constraints of the Push_swap project.

### Why Radix Sort?

- **Efficiency**: Radix Sort has a time complexity of \(O(n \cdot k)\), where \(n\) is the number of elements and \(k\) is the number of digits in the largest number. This makes it a great choice for sorting large stacks.
- **Simplicity**: The algorithm is straightforward to implement and adapts well to the operations allowed in Push_swap.
- **Scalability**: Radix Sort performs consistently well for stacks of varying sizes, including 100 and 500 elements.

### How It Works in Push_swap

1. The algorithm processes the integers bit by bit (binary representation), starting from the least significant bit (LSB) to the most significant bit (MSB).
2. At each step, the stack is divided into two groups based on the current bit:
   - Numbers with a `0` in the current bit are pushed to stack **B**.
   - Numbers with a `1` in the current bit remain in stack **A**.
3. After processing all bits, the numbers are sorted in ascending order in stack **A**.

This approach minimizes the number of operations while ensuring correctness.

---

## Evaluation

The project is evaluated based on:

- Correctness: Does your program sort the stack correctly?
- Efficiency: How many operations does your program use to sort the stack?
- Code Quality: Is your code clean, modular, and well-documented?

The number of operations is particularly important for larger stacks:
- **5 elements**: Maximum of 12 operations.
- **100 elements**: Aim for fewer than 700 operations.
- **500 elements**: Aim for fewer than 5500 operations.

---

## Resources

Here are some resources to help you with the project:

- [42 Project PDF](https://github.com/42School/push_swap)
- [Sorting Algorithms Explained](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Big-O Complexity Cheat Sheet](https://www.bigocheatsheet.com/)
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
