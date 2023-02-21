#include "main.h"

/**
* _islower - checks for lowercase characters
* @c: the character to check
* Return: 1 for the lowercase or 0 for anything else
*/

int _islower(int c)
{
if (c >= 97 && c <= 122)
{
return (1);
}
return (0);
}
