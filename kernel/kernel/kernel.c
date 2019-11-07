#include <stdio.h>
#include <kernel/tty.h>
#include <limits.h>

void kernel_main(void) 
{
    terminal_initialize();
    printf("Hello, kernel World!\n");
    for (size_t i = 0; i < 12; i++)
    {
        printf("Num: %i\n", i);
    }
    printf("printf() with char: '%c', int: %i, and string: \"%s\"\n",
        'c', 15, "hello!");
    
    printf("This is a very long line that should go well past 80 chars, %s\n",
        "in fact it should probably wrap around to the next line.");
    printf("We can also scroll...\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Display big numbers: %i\n", INT_MAX);
    printf("...and small ones: %i\n", INT_MIN);
}