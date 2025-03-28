#!/usr/bin/python3
import sys

def print_usage_and_exit(message, exit_code):
    print(message)
    sys.exit(exit_code)

# Vérification des arguments
if len(sys.argv) != 2:
    print_usage_and_exit("Usage: nqueens N", 1)

try:
    N = int(sys.argv[1])
except ValueError:
    print_usage_and_exit("N must be a number", 1)

if N < 4:
    print_usage_and_exit("N must be at least 4", 1)

def is_safe(board, row, col):
    # Vérifie s’il y a une reine sur la même colonne
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solve_nqueens(row, board, solutions):
    if row == N:
        solution = [[i, board[i]] for i in range(N)]
        solutions.append(solution)
        return
    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(row + 1, board, solutions)

solutions = []
board = [-1] * N
solve_nqueens(0, board, solutions)

for sol in solutions:
    print(sol)
