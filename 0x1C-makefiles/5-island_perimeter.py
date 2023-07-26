#!/usr/bin/python3
"""
This module has a method tha calculates the perimeter
of an island in a grid
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island in the grid
    """

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                """
                 If the cell is outside the grid or adjacent to water,
                 add 1 to the perimeter
                """
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1
                if row == rows - 1 or grid[row + 1][col] == 0:
                    perimeter += 1
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1
                if col == cols - 1 or grid[row][col + 1] == 0:
                    perimeter += 1

    return perimeter
