#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_st(int st, int file_des, char *file_n, char type);
/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int shr, destiny, num_read = 1024, wrote, close_shr, close_destiny;
	unsigned int type = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	shr = open(argv[1], O_RDONLY);
	check_st(shr, -1, argv[1], 'O');
	destiny = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, type);
	check_st(destiny, -1, argv[2], 'W');
	while (num_read == 1024)
	{
		num_read = read(shr, buf, sizeof(buf));
		if (num_read == -1)
			check_st(-1, -1, argv[1], 'O');
		wrote = write(destiny, buf, num_read);
		if (wrote == -1)
			check_st(-1, -1, argv[2], 'W');
	}
	close_shr = close(shr);
	check_st(close_shr, shr, NULL, 'C');
	close_destiny = close(destiny);
	check_st(close_destiny, destiny, NULL, 'C');
	return (0);
}

/**
 * check_st - cle can be opened or closed
 * @st: file descriptor of the file to be opened
 * @file_n: name of the file
 * @type: closing or opening
 * @file_des: file descriptor
 *
 * Return: void
 */
void check_st(int st, int file_des, char *file_n, char type)
{
	if (type == 'C' && st == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant close file_des %d\n", file_des);
		exit(100);
	}
	else if (type == 'O' && st == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant read file %s\n", file_n);
		exit(98);
	}
	else if (type == 'W' && st == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant write  %s\n", file_n);
		exit(99);
	}
}