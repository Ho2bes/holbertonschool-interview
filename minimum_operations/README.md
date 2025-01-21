# Minimum Operations

## Project Overview
The **Minimum Operations** project is a Python exercise designed to calculate the minimum number of operations needed to achieve exactly `n` characters of `H` in a text file. The operations available are:
- **Copy All**: Copies all the characters in the file to memory.
- **Paste**: Pastes the copied characters to the end of the text in the file.

The goal is to determine the optimal sequence of operations to minimize the total number of steps.

---

## Requirements
### General
- **Editors**: Allowed editors include `vi`, `vim`, and `emacs`.
- **Environment**: Files will be interpreted or compiled on **Ubuntu 14.04 LTS** using **Python 3.4.3**.
- **File Standards**:
  - All files must end with a new line.
  - The first line of each file should be: `#!/usr/bin/python3`.
  - All files must be executable.
  - A `README.md` file is mandatory at the root of the project folder.
- **Code Style**:
  - Code must follow the **PEP 8** style guide (version 1.7.x).
  - Code must include appropriate documentation.

---

## Tasks

### Task 0: Minimum Operations
**Description**:
Write a function that calculates the fewest number of operations needed to result in exactly `n` characters in the file.

**Prototype**:
```python
#!/usr/bin/python3
def minOperations(n):
```
- Returns an integer representing the minimum number of operations.
- Returns `0` if achieving `n` characters is impossible.

**Example Usage**:
```python
n = 9
H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6
```

#### Example Input and Output:
```bash
carrie@ubuntu:~/minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/minoperations$
carrie@ubuntu:~/minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/minoperations$
```

---

## Repository Structure
```
minimum_operations/
├── 0-minoperations.py  # Main Python script containing the function
├── 0-main.py           # Test script for the function
├── README.md           # Project documentation
```

---

## How It Works
The function `minOperations(n)` works by finding the prime factors of `n`. Each prime factor contributes to the number of operations:
- If `n` can be divided by a smaller number `k`, it implies that a "Copy All" followed by multiple "Paste" operations is needed to reach `k` characters.
- By summing up these factors, the minimum number of operations can be calculated.

### Algorithm Steps:
1. Start with `total_ops = 0` to track the number of operations.
2. Use a loop to divide `n` by its smallest factor greater than 1 until `n == 1`.
3. Add each factor to `total_ops`.
4. Return `total_ops`.

---

## Example Code Walkthrough
**Input**: `n = 9`

1. Prime factors of 9: `3, 3`.
2. Operations:
   - Copy All (3 characters): `1 operation`.
   - Paste (3 characters to 6): `1 operation`.
   - Copy All (6 characters): `1 operation`.
   - Paste (6 characters to 9): `1 operation`.
3. **Total Operations**: `6`.

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/holbertonschool-interview.git
   cd holbertonschool-interview/minimum_operations
   ```
2. Ensure the files are executable:
   ```bash
   chmod +x 0-main.py 0-minoperations.py
   ```
3. Run the test file:
   ```bash
   ./0-main.py
   ```
