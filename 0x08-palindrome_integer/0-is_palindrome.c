#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check if a palindrome
 * @n: input
 * Return: output
 */

int is_palindrome(unsigned long n)

{
int a = 0;
int b = 0;
int x = n;

	while (n != 0)
		{
		a = n % 10;
		b = b * 10 + a;
		n = n / 10;
		}
	if (b == x)
		return (1);
	return (0);
}