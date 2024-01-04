#!/usr/bin/python3

"""
    method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
        Return True if all boxes can be opened, else return False
    """
    newBox = set()
    firstBox = boxes[0]
    newBox.add(0)
    while firstBox:
        key = firstBox.pop()
        if key < len(boxes) and key not in newBox:
            newBox.add(key)
            firstBox.extend(boxes[key])
    return len(newBox) == len(boxes)
