#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_mc(unsigned char *e_ident);
void print_c(unsigned char *e_ident);
void print_d(unsigned char *e_ident);
void print_v(unsigned char *e_ident);
void show_abi(unsigned char *e_ident);
void print_os(unsigned char *e_ident);
void show_type(unsigned int e_type, unsigned char *e_ident);
void print_ent(unsigned long int e_entry, unsigned char *e_ident);
void cls_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 *
 */
void check_elf(unsigned char *e_ident)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_ident[indx] != 127 &&
			e_ident[indx] != 'E' &&
			e_ident[indx] != 'L' &&
			e_ident[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(0);
		}
	}
}

/**
 * print_mc - Prints the magic numbers of an ELF header.
 *
 */
void print_mc(unsigned char *e_ident)
{
	int indx;

	printf("  Magic:   ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_ident[indx]);

		if (indx == EI_NIDENT - 1)
			putchar('\n');
		else
		putchar('\n');
	}
}

/**
 * print_c - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_c(unsigned char *e_ident)
{
	printf("  Class:                            ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_d(unsigned char *e_ident)
{
	printf("  Data:                               ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_v - Prints the version of an ELF header.
 * @e_ident: A pointer to an array
 */
void print_v(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_os - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array 
 */
void print_os(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * show_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array 
 */
void show_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * @e_type: The ELF type.
 */
void show_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

 /* @e_ident: A pointer to an array 
 */
void print_ent(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * cls_elf - Closes an ELF file.
 * @elf: The file descriptor
 *
 * Description: checks If the file cannot be closed
 */
void cls_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);

		exit(0);
	}
}

/**
 * main - Displays info
 * @argv: the arguments.
 *
 * Return: 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *hd;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(0);
	}
	hd = malloc(sizeof(Elf64_Ehdr));
	if (hd == NULL)
	{
		cls_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(0);
	}
	r = read(o, hd, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		cls_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(0);
	}

	check_elf(hd->e_ident);
	printf("ELF Header:\n");
	print_mc(hd->e_ident);
	print_c(hd->e_ident);
	print_d(hd->e_ident);
	print_v(hd->e_ident);
	print_os(hd->e_ident);
	show_abi(hd->e_ident);
	show_type(hd->e_type, hd->e_ident);
	print_ent(hd->e_entry, hd->e_ident);

	cls_elf(o);
	return (0);
}
