# 42SP-PushSwap

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

This repository contains the PushSwap project developed as part of the 42 São Paulo curriculum.

## Table of Contents

- [Introduction](#introduction)
- [Rules](#rules)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

42SP-PushSwap is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations. The goal is to develop an efficient algorithm that can sort the stack with the minimum number of moves.

The project involves two stacks, named Stack A and Stack B. Initially, Stack A contains a random list of integers, and Stack B is empty. The task is to sort the integers in Stack A in ascending order using a set of predefined operations, such as swapping, pushing, and rotating elements between the stacks.

The project challenges your algorithmic thinking, problem-solving skills, and ability to optimize the sorting process. It requires careful planning and implementation of the sorting algorithm to minimize the number of moves and achieve the desired result.

## Rules

The rules for the PushSwap project are as follows:

1. The game is played with two stacks, A and B.
2. Initially, Stack A contains a random list of unique integers, and Stack B is empty.
3. The goal is to sort the integers in Stack A in ascending order.
4. Only the following operations are allowed:
   - `sa`: swap the first two elements of Stack A.
   - `sb`: swap the first two elements of Stack B.
   - `ss`: swap the first two elements of both stacks.
   - `pa`: push the first element of Stack B to Stack A.
   - `pb`: push the first element of Stack A to Stack B.
   - `ra`: rotate all elements of Stack A up by one.
   - `rb`: rotate all elements of Stack B up by one.
   - `rr`: rotate all elements of both stacks up by one.
   - `rra`: rotate all elements of Stack A down by one.
   - `rrb`: rotate all elements of Stack B down by one.
   - `rrr`: rotate all elements of both stacks down by one.
5. The program must output a list of the operations performed to sort Stack A.

## Usage

To use the PushSwap program, follow these steps:

1. Clone the repository to your local machine using the following command:

```
git clone https://github.com/maidell/42SP-PushSwap.git
```

2. Navigate to the project directory:

```shell
cd 42SP-PushSwap
```


3. Compile the program using the Makefile:

```shell
make
```


4. Run the program with a list of integers as arguments:

```shell
./push_swap 3 2 1
```


Replace `3 2 1` with your own list of integers.

5. The program will output a list of operations to sort the stack. You can also use the `checker` program to validate the sorting:


```shell
./push_swap 3 2 1 | ./checker 3 2 1
```


Replace `3 2 1` with the same list of integers used for the `push_swap` program.

Feel free to explore the project, review the implementation, and test the program with different sets of integers.

## Contributing

Contributions to this project are not currently accepted, as it represents my own implementation of the PushSwap project. However, you can fork the repository and modify the code for your own use or create your own version of the project.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) - see the [LICENSE](LICENSE) file for more details.
