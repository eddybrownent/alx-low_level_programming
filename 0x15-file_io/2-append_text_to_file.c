#include "main.h"

/**
* append_text_to_file - appends text at the end of a file.
* @filename: is the name of the file.
* @text_content: is the NULL terminated string to add.
* at the end of the file.
*
* Return: 1 on success / -1 on failure.
*/

int append_text_to_file(const char *filename, char *text_content)
{

int fd_to_append;
int byte_written;
int len;
if (filename == NULL)
{
return (-1);
}

fd_to_append = open(filename, O_WRONLY | O_APPEND);
if (fd_to_append == -1)
{
return (-1);
}


if (text_content != NULL)
{
len = strlen(text_content);
byte_written = write(fd_to_append, text_content, len);
}

if (byte_written == -1)
{
close(fd_to_append);
return (-1);
}


close(fd_to_append);
return (-1);
}
