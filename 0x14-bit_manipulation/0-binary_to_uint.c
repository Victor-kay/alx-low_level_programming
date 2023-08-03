#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is a non-binary char
 * or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int bit;

	if (b == NULL)
		return (0);

	for (int i = 0; b[i] != '\0'; i++)
	{
		bit = b[i] - '0'; /* Convert ASCII '0' or '1' to 0 or 1 */

		if (bit != 0 && bit != 1)
		{
			return (0); /* Return 0 if a non-binary character is found */
		}

		result = (result << 1) | bit;
	}

	return (result);
}
