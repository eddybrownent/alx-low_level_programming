#include "main.h"
#define BUFFER_SIZE 1024
/**
* main - copies file contents from one to another file
* @argv: passed arguments.
* @argc: argument count.
*
* Return: 0 if success
*
*/
int main(int argc, char *argv[])
{
FILE *file_from, *file_to;
char buffer[BUFFER_SIZE];
size_t bytes_read;
if (argc != 3)
{
printf("Usage: cp file_from file_to\n");
exit(97);
}
file_from = fopen(argv[1], "rb");
if (file_from == NULL)
{
printf("Error: Can't read from file NAME_OF_THE_FILE\n");
exit(98);
}
file_to = fopen(argv[2], "wb");
if (file_to == NULL)
{
printf("Error: can't write to NAME_OF_THE_FILE\n");
exit(99);
}
while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file_from)) > 0)
{
if (fwrite(buffer, 1, bytes_read, file_to) != bytes_read)
{
printf("Error: Can't write to file NAME_OF_THE_FILE\n");
exit(99);
}
}
if (fclose(file_from) != 0)
{
printf("Error: Can't close fd FD_VALUE\n");
exit(100);
}
if (fclose(file_to) != 0)
{
printf("Error: Can't close fd FD_VALUE\n");
exit(100);
}
return (0);
}
