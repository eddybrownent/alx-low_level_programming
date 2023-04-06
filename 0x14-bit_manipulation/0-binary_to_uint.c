#include "main.h"

/**
* binary_to_uint - convert a binary to an interger.
* @b: pointer to a string.
* Return: unsigned int or 0 if there
* is one more chars in string that
* is not 0 or 1.
*/
unsigned int binary_to_uint(const char *b)
{
int i = 0;
unsigned int num;

if (!b)
return (0);

while (b[i] != '\0')
{
if (b[i] != '1' && b[i] != '0')
return (0);
i++;
}

i = 0;
num = 0;

while (b[i] != '\0')
{
num = num << 1;
if (b[i] == '1')
num = num + 1;
++i;
}
return (num);
}

