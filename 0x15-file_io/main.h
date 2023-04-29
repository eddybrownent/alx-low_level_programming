#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int _putchar(char c);
ssize_t read_textfile(const char *file_n, size_t letters);
int create_file(const char *file_n, char *text_content);
int append_text_to_file(const char *file_n, char *text_content);


#endif
