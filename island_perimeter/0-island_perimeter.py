#!/usr/bin/python3
"""
Module to calculate the perimeter of an island described in a grid.
"""

def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid (List[List[int]]): 2D list representing the map.

    Returns:
        int: perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                # Check top neighbor
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                # Check left neighbor
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
