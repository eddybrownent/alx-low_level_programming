#include "main.h"

char *c_buf(char *file);
void cls_file(int fd);

/**
* create_buffer - allocates byte for a buffer.
* @file: name of file buffer is storing chars for.
*
* Return: a pointer to the buffer.
*/

char *c_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
* main - copies the contents of a file to another file.
* @argc: no of arguments given to the program
* @argv: the array of pointers to the arguments.
*
* Return: 0 on success.
*/

int main(int argc, char *argv[])
{
	int src, des, x, i;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = c_buf(argv[2]);
	src = open(argv[1], O_RDONLY);
	x = read(src, buf, 1024);
	des = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}
		i = write(des, buf, x);
		if (des == -1 || i == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}
		x = read(src, buf, 1024);
		des = open(argv[2], O_WRONLY | O_APPEND);
	} while (x > 0);

	free(buf);
	cls_file(src);
	cls_file(des);

	return (0);
}

/**
* cls_file - closes file descriptors.
* @fd: file descriptors to be closed.
* Return: nothing
*/

void cls_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}