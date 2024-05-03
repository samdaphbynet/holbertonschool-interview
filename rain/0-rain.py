#!/usr/bin/python3
"""
Description: Given a list of non-negative integers representing walls of
width 1, calculate how much water will be retained after it rains.

- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index
  walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.
"""

def rain(walls):
    """
    Args:
        walls - is a list of non-negative integers.
    Returns:
        If the list is empty return 0.
    """
    if not walls:
        return 0
    
    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    left_max[0] = walls[0]
    right_max[n - 1] = walls[n - 1]
    
    # Calculate the maximum height seen so far on the left side of each wall
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])
    
    # Calculate the maximum height seen so far on the right side of each wall
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])
    
    # Calculate the amount of water retained at each position
    water = 0
    for i in range(n):
        water += max(0, min(left_max[i], right_max[i]) - walls[i])
    
    return water
