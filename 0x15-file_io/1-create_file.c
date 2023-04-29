#include "main.h"

/**
* create_file - create a file.
* @file_n: is the name of the file to create.
* @text_content: NULL terminated string to write to the file.
* Return: 1 on success / -1 on failure
*/

int create_file(const char *file_n, char *text_content)
{

int char_written;
int file_des_to_create;
if (file_n == NULL)
{
return (-1);
}

file_des_to_create = open(file_n, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_des_to_create == -1)
{
return (-1);
}


if (text_content != NULL)
{
char_written = write(file_des_to_create, text_content, strlen(text_content));
if (char_written == -1)
{
close(file_des_to_create);
return (-1);
}
}

close(file_des_to_create);
return (1);
}
