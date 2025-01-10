# Insert in Sorted Linked List

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`.
- All files will be compiled on **Ubuntu 14.04 LTS**.
- Compilation is done with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra -pedantic`.
- All files must end with a new line.
- Code must follow the **Betty style** (checked using `betty-style.pl` and `betty-doc.pl`).
- Global variables are not allowed.
- No more than **5 functions** per file.
- The `main.c` files provided in examples are for testing purposes only and should not be pushed.
- Custom `main.c` files may be used during evaluation.
- All function prototypes should be included in a header file called `lists.h`.
- A `README.md` file at the root of the project folder is mandatory.
- Header files must be include-guarded.

---

## Tasks

### 0. Insert in Sorted Linked List
**Mandatory**

#### Description
Write a function in C that inserts a number into a sorted singly linked list.

#### Prototype
```c
listint_t *insert_node(listint_t **head, int number);
