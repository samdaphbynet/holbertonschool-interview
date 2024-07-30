#!/usr/bin/python3


def island_perimeter(grid):
    """
    Calculates the perimeter of an island in a 2D grid.
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4  # Add 4 sides for the current cell

                # Check if there's a cell above
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Subtract 2 sides since they are counted twice

                # Check if there's a cell to the left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Subtract 2 sides since they are counted twice

    return perimeter