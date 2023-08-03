#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is a non-binary char or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (; *b != '\0'; b++)
	{
		if (*b == '0')
		{
			result <<= 1; /* Shift left by 1 position */
		}
		else if (*b == '1')
		{
			result = (result << 1) | 1; /* Shift left and OR with 1 */
		}
		else
		{
			return (0); /* Return 0 if a non-binary character is found */
		}
	}

	return (result);
}

int main(void)
{
	const char *binary_str = "101010";
	unsigned int result = binary_to_uint(binary_str);
	printf("Converted number: %u\n", result);

	return (0);
}
