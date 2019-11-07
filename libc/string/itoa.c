#include <string.h>
#include <stdbool.h>

char * itoa(const int i)
{
    int idx = 0;
    // max negative int, with '-' and null terminator, is len 11
    static unsigned char buffer[11]; 
    bool negative = i < 0;
    unsigned int ui = negative ? -i : i;

    while (ui != 0)
    {
        buffer[idx++] = ui % 10 + '0';
        ui = ui / 10;
    }

    if (negative)
    {
        buffer[idx++] = '-';
    }

    buffer[idx] = '\0';

    // XOR swap
    for (int t = 0; t < idx/2; t++)
    {
        buffer[t] ^= buffer[idx-t-1];
        buffer[idx-t-1] ^= buffer[t];
        buffer[t] ^= buffer[idx-t-1];
    }

    if (i == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }

    return buffer;
}