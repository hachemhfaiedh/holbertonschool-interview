#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened
    """
    keys = [0]
    for i, k in enumerate(boxes):
        for j in k:
            if j != i and j not in keys and j < len(boxes):
                keys.append(j)
    return len(keys) == len(boxes)
    else:
        return False