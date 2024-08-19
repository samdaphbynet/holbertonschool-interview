#!/usr/bin/python3
'''
Returns a list of lists representing the first 'n' lines of Pascal's Triangle.
'''


def pascal_triangle(n):
    ''' Generates Pascal's Triangle up to the 'n' line. '''
    triangle = []
    for i in range(n):
        row = [1]
        if i > 0:
            for j in range(1, i):
                row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
            row.append(1)
        triangle.append(row)
    return triangle
