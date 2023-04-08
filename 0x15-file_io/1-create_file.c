#include "main.h"

/**
* create_file - create a file.
* @filename: is the name of the file to create.
* @text_content: NULL terminated string to write to the file.
* Return: 1 on success / -1 on failure
*/

int create_file(const char *filename, char *text_content)
{

int char_written;
int fd_to_create;
if (filename == NULL)
{
return (-1);
}

fd_to_create = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd_to_create == -1)
{
return (-1);
}


if (text_content != NULL)
{
char_written = write(fd_to_create, text_content, strlen(text_content));
if (char_written == -1)
{
close(fd_to_create);
return (-1);
}
}

close(fd_to_create);
return (1);
}
