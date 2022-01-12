#include "holberton.h"

/**
 * _print - prints each string number
 * @s: pointer to the string
 * Return: void
 */
void _print(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		puts(s + 1);
	}
}

/**
 * _is_digit - check whether s is a number
 * @s: pointer to the string
 * Return: 0 | 1
 */
int _is_digit(char *s)
{
	int i, d = 0;

	for (i = 0; s[i] && !d; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			d++;
	}
	return (d);
}

/**
 * _ops - performs and returns multiplication and addition
 * @n1: first number
 * @n2: second number
 * @l1: length of n1
 * @l2: length of n2
 * Return: result of operations
 */
char *_ops(char *n1, char *n2, int l1, int l2)
{
	char *r = NULL;
	int i, j, aux, len = l1 + l2;

	r = malloc(sizeof(char) * len);
	if (!r)
	{
		_print("Error");
		exit(98);
	}
	for (i = 0; i < len; i++)
		r[i] = '0';
	for (i = l1 - 1; i >= 0; i--)
	{
		aux = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			aux += (n1[i] - '0') * (n2[j] - '0');
			aux += r[i + j + 1] - '0';
			r[i + j + 1] = (aux % 10) + '0';
			aux /= 10;
		}
		if (aux)
			r[i + j + 1] = (aux % 10) + '0';
	}
	return (r);
}

/**
 * main - multiplies two positive numbers
 * @av: double pointer to num1, num2
 * @ac: arguments counter
 * Return: 0 | 98
 */
int main(int ac, char **av)
{
	int l1 = 0, l2 = 0;
	char *n1 = av[1], *n2 = av[2], *r = NULL;

	if (ac != 3 || _is_digit(n1) || _is_digit(n2))
	{
		_print("Error");
		exit(98);
	}
	if (av[1][0] == 48 || av[2][0] == 48)
	{
		_print("0");
		exit(0);
	}
	while (n1[l1])
		l1++;
	while (n2[l2])
		l2++;

	r = _ops(n1, n2, l1, l2);
	if (r[0] == '0')
		_print(r + 1);
	else
		_print(r);
	free(r);
	return (0);
}
