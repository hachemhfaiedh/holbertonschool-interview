#!/usr/bin/python3
""" Minimum operations """


def minOperations(n):
    a = 2
    count = 0
    while n > 1:
        while n % a == 0:
            count += a
            n = n // a
        a += 1
    return count
