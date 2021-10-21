#!/usr/bin/python3
"""N queens"""
import sys


def check_queen(p):
    """N queens"""
    for i in range(len(p) - 1):
        d = p[i] - p[len(p) - 1]
        if d == 0 or d * (-1) == len(p) - 1 - i or d == len(p) - 1 - i:
            return False
    return True


def n_queen(N, r, sol, p):
    """N queens"""
    if r == N:
        print(sol)
    else:
        for i in range(N):
            p.append(i)
            sol.append([r, i])
            if check_queen(p):
                n_queen(N, r + 1, sol, p)
            p.pop()
            sol.pop()


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)
try:
    n = int(sys.argv[1])
except Exception:
    print("N must be a number")
    sys.exit(1)
if n < 4:
    print("N must be at least 4")
    sys.exit(1)
solution = []
pos = []
row = 0
n_queen(n, row, solution, pos)
