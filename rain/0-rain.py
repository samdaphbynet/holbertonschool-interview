#!/bin/env python

def rain(walls):
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
