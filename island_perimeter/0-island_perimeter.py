def island_perimeter(grid):
    if not grid:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Start with 4 sides
                perimeter += 4

                # Subtract sides shared with land above
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2  # one for current and one for neighbor

                # Subtract sides shared with land to the left
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter
