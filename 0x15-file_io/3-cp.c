#include "main.h"
#define BUFFER_SIZE 1024
/**
* main - copies file contents from one to another file
* @argv: passed arguments.
* @argc: argument count.
* Return: 0 if success
*/
int main(int argc, char *argv[])
{
int fd_to, fd_from, num_write, num_read;
char buffer[BUFFER_SIZE];
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
exit(99);
}
while ((num_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
num_write = write(fd_to, buffer, num_read);
if (num_write != num_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
exit(99);
}
}
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd_from);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd_to);
exit(100);
}
return (0);
}
