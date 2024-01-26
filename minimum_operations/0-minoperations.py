#!/usr/bin/python3

def minOperations(n):
    if  n <= 0:
        return 0
    
    operations = 0
    current_factor = 2

    while n > 1:
        while n % current_factor ==0:
            n //= current_factor
            operations += current_factor
        current_factor += 1
    
    return operations
