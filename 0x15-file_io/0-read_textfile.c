#include "main.h"
/**
* read_textfile - reads a text file and prints it.
* @letters: numbers of characters to read.
* @filename: name of the file.
* Return: number of letters it could read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer = NULL;
ssize_t char_read = 0;
int fd_to_read = -1;

if (filename == NULL)
{
return (0);
}


fd_to_read = open(filename, O_RDONLY);
if (fd_to_read ==  -1)
{
return (0);
}

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(fd_to_read);
return (0);
}

char_read = read(fd_to_read, buffer, letters);
if (char_read == -1)
{
close(fd_to_read);
free(buffer);
return (0);
}

buffer[char_read] = '\0';
write(STDOUT_FILENO, buffer, char_read);

close(fd_to_read);
free(buffer);


return (char_read);
}