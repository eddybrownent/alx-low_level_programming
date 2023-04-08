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
FILE *fp = NULL;
ssize_t char_read = 0;

if (filename == NULL)
{
return (0);
}


fp = fopen(filename, "r");
if (fp == NULL)
{
return (0);
}

buffer = malloc(letters + 1);
if (buffer == NULL)
{
fclose(fp);
return (0);
}

char_read = fread(buffer, sizeof(char), letters, fp);
if (char_read == 0)
{
fclose(fp);
free(buffer);
return (0);
}

buffer[char_read] = '\0';
printf("%s", buffer);

fclose(fp);
free(buffer);


return (char_read);
}
