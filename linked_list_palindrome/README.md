# Linked List Palindrome Checker

## Overview

This project involves creating a function in C to check if a singly linked list is a palindrome. The project is part of technical interview preparation and adheres to specific coding standards and requirements.

## Requirements

### General

- **Allowed Editors**: vi, vim, emacs
- **Compilation**: All files will be compiled on Ubuntu 14.04 LTS.
- **Compiler**: Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra` and `-pedantic`.
- **File Endings**: All files should end with a new line.
- **Coding Style**: Code should use the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`.
- **Global Variables**: Not allowed.
- **Functions per File**: No more than 5 functions per file.
- **Header File**: Prototypes of all functions should be included in a header file called `lists.h`.
- **Include Guards**: All header files should be include guarded.

### Tasks

#### 0. Linked list palindrome

- **Objective**: Write a function in C that checks if a singly linked list is a palindrome.
- **Prototype**: `int is_palindrome(listint_t **head);`
- **Return**: `0` if it is not a palindrome, `1` if it is a palindrome.
- **Edge Case**: An empty list is considered a palindrome.

## Project Structure

- `lists.h`: Header file containing the structure definition and function prototypes.
- `linked_lists.c`: Implementation of helper functions for linked list operations.
- `0-main.c`: Example main file to test the `is_palindrome` function.
- `0-is_palindrome.c`: Implementation of the palindrome checking function.

## Usage

1. Clone the repository.
2. Compile the program using the provided `gcc` command:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
