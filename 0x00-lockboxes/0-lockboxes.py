#!/usr/bin/python3
def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    lb = []
    b = len(boxes)
    for i in boxes:
        if len(i) == 0 and i is not boxes[b-1]:
            return False
        for j in i:
            lb.append(j)
    for index, keys in enumerate(boxes):
        if index in lb or index < b-1:
            return True
        else:
            return False