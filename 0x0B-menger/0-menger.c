#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * function - function
 * @i: input
 * @j: input
 * Return: output
 */

int function(int i, int j)
{
while (i && j)
{
if (i % 3 == 1 && j % 3 == 1)
	return (0);
i /= 3;
j /= 3;
}
return (1);
}

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: input
 * Return: output
 */
void menger(int level)
{
int a, b, c;
if (level < 0)
	return;
for (a = 0, c = pow(3, level); a < c; a++)
	{
	for (b = 0; b < c; b++)
		if (function(a, b))
		printf("%c", '#');
		else
		printf("%c", ' ');
	printf("\n");
	}
}
