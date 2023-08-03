#include <stddef.h>
#include <stdio.h>

unsigned int binary_to_uint(const char *b)
{
    if (b == NULL)
        return 0;

    unsigned int result = 0;
    int bit;

    while (*b != '\0') {
        bit = *b - '0';
        if (bit != 0 && bit != 1)
            return 0;

        result = (result << 1) | bit;
        b++;
    }

    return result;
}
