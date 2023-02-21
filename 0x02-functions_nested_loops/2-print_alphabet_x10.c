#include "main.h"

/**
* print_alphabet_x10- prints alpabets 10 times
*
*/
void print_alphabet_x10(void)
{
int lines;
char alpha;

for (lines = 0; lines <= 9; lines++)
{
for (alpha = 'a'; alpha <= 'z'; alpha++)
_putchar(alpha);
_putchar('\n');
}
}
