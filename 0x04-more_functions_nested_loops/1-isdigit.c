#include "main.h"
/**
* _isdigit - checks for a digit
* @x: character to be checked if its a digit
* Return: 1 for a digit otherwise return 0
*/

int _isdigit(int x)
{
if (x >= '0' && x <= '9')
{
return (1);
}
return (0);
}
