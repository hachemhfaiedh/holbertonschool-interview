#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"
/**
 * slide_line - slides and merges an array of integers
 * @line: input
 * @size: input
 * @direction: input
 * Return: output
 */

int slide_line(int *line, size_t size, int direction)
{

int a = size - 1, b, pr = 0, cur;
	if ((direction != 0 && direction != 1) || ((line == NULL || size < 1)))
	return (0);

	if (direction == 1)
		{
		for (b = size - 1; b >= 0; b--)
			{
			cur = line[b];
			if (!cur)
			continue;
			if (!pr)
			pr = cur;
			else if (pr == cur)
				{
				line[a--] = cur << 1;
				pr = 0;
				}
			else
				{
				line[a--] = pr;
				pr = cur;
				}
			}
		if (pr)
		line[a--] = pr;
		while (a >= 0)
		line[a--] = 0;
		}

	if (direction == 0)
	move_left(line, size);
	return (1);
}

/**
 * move_left - move direction to left
 * @line: input
 * @size: output
 */

void move_left(int *line, size_t size)
{
	int i = 0, j, prv = 0, curr;
	for (j = 0; j < (int)size; j++)
		{
		curr = line[j];
		if (!curr)
		continue;
		if (!prv)
		prv = curr;
		else if (prv == curr)
			{
			line[i++] = curr << 1;
			prv = 0;
			}
		else
			{
			line[i++] = prv;
			prv = curr;
			}
		}
		if (prv)
		line[i++] = prv;
		while (i < (int)size)
		line[i++] = 0;
}
