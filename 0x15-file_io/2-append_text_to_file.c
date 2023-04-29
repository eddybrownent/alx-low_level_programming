#include "main.h"

/**
* append_text_to_file - appends text at the end of a file.
* @file_n: is the name of the file.
* @text_content: is the NULL terminated string to add.
* at the end of the file.
*
* Return: 1 on success / -1 on failure.
*/

int append_text_to_file(const char *file_n, char *text_content)
{

int file_des_to_append;
int byte_written;
int len;
if (file_n == NULL)
return (-1);


file_des_to_append = open(file_n, O_WRONLY | O_APPEND);
if (file_des_to_append == -1)
return (-1);

if (text_content != NULL)
{
len = strlen(text_content);
byte_written = write(file_des_to_append, text_content, len);
if (byte_written == -1)
{
close(file_des_to_append);
return (-1);
}
}

close(file_des_to_append);
return (1);
}
