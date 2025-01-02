#!/usr/bin/python3
"""
Module to determine if all lockboxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    :param boxes: List of lists containing keys.
    :return: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    opened = set([0])     # Box 0 is already unlocked
    stack = [0]           # Stack for performing DFS, starting from box 0

    while stack:
        current = stack.pop()  # Remove the top element from the stack
        for key in boxes[current]:  # Iterate over each key found in the  box
            if 0 <= key < n and key not in opened:
                opened.add(key)    # Mark the box as unlocked
                stack.append(key)  # Add the newly unlocked bx to the stack

    return len(opened) == n  # Check if all boxes are unlocked
