#include "main.h"
/**
* read_textfile - reads a text file and prints it.
* @letters: numbers of characters to read.
* @file_n: name of the file.
* Return: number of letters it could read and print.
*/
ssize_t read_textfile(const char *file_n, size_t letters)
{
char *buf = NULL;
ssize_t char_read = 0;
int file_des_to_read = -1;

if (file_n == NULL)
{
return (0);
}


file_des_to_read = open(file_n, O_RDONLY);
if (file_des_to_read ==  -1)
{
return (0);
}

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(file_des_to_read);
return (0);
}

char_read = read(file_des_to_read, buf, letters);
if (char_read == -1)
{
close(file_des_to_read);
free(buf);
return (0);
}

buf[char_read] = '\0';
write(STDOUT_FILENO, buf, char_read);

close(file_des_to_read);
free(buf);


return (char_read);
}
