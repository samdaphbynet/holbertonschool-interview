#!/usr/bin/python3
"""
Defines function that returns a list of lists of integers
"""


def pascal_triangle(n):
    """
    Creates a list of lists of integers representing Pascal's triangle
    """
    triangle = []
    for i in range(n):
        row = [1]
        if i > 0:
            for j in range(1, i):
                row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
            row.append(1)
        triangle.append(row)
    return triangle
