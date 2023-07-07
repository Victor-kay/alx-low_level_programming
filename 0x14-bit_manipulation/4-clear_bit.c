/**
 * clear_bit - clears the value of a bit at a given index
 * @n: pointer to the number to modify
 * @index: index of the bit to clear
 *
 * Return: 1 on success, -1 if the index is out of range
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
