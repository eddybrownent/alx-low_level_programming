#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - copies the contents of one file to another
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, or an error code otherwise
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to, rd_len = 0, wr_len = 0;
char buffer[BUFFER_SIZE];
if (argc != 3)
error_exit(97, "Usage: cp file_from file_to\n");
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);
while ((rd_len = read(fd_from, buffer, BUFFER_SIZE)))
{
if (rd_len == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
wr_len = write(fd_to, buffer, rd_len);
if (wr_len == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);
if (wr_len != rd_len)
error_exit(99, "Error: Incomplete write to %s\n", argv[2]);
}
if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd %d\n", fd_from);
if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd %d\n", fd_to);
return (0);
}
