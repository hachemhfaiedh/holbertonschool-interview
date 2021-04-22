#!/usr/bin/python3
"""Lockboxes"""


"""def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened
    """
    keys = [0]
    for i, k in enumerate(boxes):
        for j in k:
            if j != i and j not in keys and j < len(boxes):
                keys.append(j)
    if len(keys) == len(boxes):
        return True
    else:
        return False"""
def canUnlockAll(boxes):
    newlist = []
    k = len(boxes)
    for i in boxes:
        if len(i) == 0 and i is not boxes[k-1]:
            return False
        for j in i:
            newlist.append(j)
    print(newlist)
    for index, keys in enumerate(boxes):
        if index in newlist or index < k-1:
            return True
        else:
            return False