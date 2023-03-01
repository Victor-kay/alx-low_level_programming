#include "main.h"
#include <stdio.h>

/**
 * print_rev - Prints a string in reverse
 * @s: The string to print
 */

void print_rev(char *s)

{
	
	int i = 0;

	while (s[i] != '\0')
		i++;
	for (i = i - i; i >= 0; i--)
		_putchar(s[c]);

	_putchar('\n');
}
