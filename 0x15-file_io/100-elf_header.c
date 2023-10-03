#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | (((n << 16) >> 24) << 16) | (n >> 24))

void verify(unsigned char *e_ident)
{
    if (*(e_ident) == 0x7f && *(e_ident + 1) == 'E' && *(e_ident + 2) == 'L' && *(e_ident + 3) == 'F')
    {
        printf("ELF Header:\n");
    }
    else
    {
        dprintf(STDERR_FILENO, "Error: this file is not a valid ELF\n");
        exit(98);
    }
}

void magic(unsigned char *e_ident)
{
    int i;
    int limit;

    limit = EI_NIDENT - 1;
    printf("  Magic:   ");
    for (i = 0; i < limit; i++)
        printf("%02x ", *(e_ident + i));
    printf("%02x\n", *(e_ident + i));
}

void class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    if (e_ident[EI_CLASS] == ELFCLASSNONE)
        printf("This class is invalid\n");
    else if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

void data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    if (e_ident[EI_DATA] == ELFDATANONE)
        printf("Unknown data format\n");
    else if (e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

void version(unsigned char *e_ident)
{
    printf("  Version:                           ");
    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf("%i (current)\n", EV_CURRENT);
    else
        printf("%i\n", e_ident[EI_VERSION]);
}

void osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    if (e_ident[EI_OSABI] == ELFOSABI_SYSV)
        printf("UNIX - System V\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
        printf("UNIX - HP-UX\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
        printf("UNIX - NetBSD\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
        printf("UNIX - Linux\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
        printf("UNIX - Solaris\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
        printf("UNIX - IRIX\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
        printf("UNIX - FreeBSD\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
        printf("UNIX - TRU64\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
        printf("ARM\n");
    else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
        printf("Standalone App\n");
    else
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

void type(unsigned int e_type, unsigned char *e_ident)
{
    e_ident[EI_DATA] == ELFDATA2MSB ? e_type = e_type >> 8 : e_type;

    printf("  Type:                              ");
    if (e_type == ET_NONE)
        printf("NONE (Unknown type)\n");
    else if (e_type == ET_REL)
        printf("REL (Relocatable file)\n");
    else if (e_type == ET_EXEC)
        printf("EXEC (Executable file)\n");
    else if (e_type == ET_DYN)
        printf("DYN (Shared object file)\n");
    else if (e_type == ET_CORE)
        printf("CORE (Core file)\n");
    else
        printf("<unknown: %x>\n", e_type);
}

void entry(unsigned int e_entry, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_entry = REV(e_entry);

    printf("  Entry point address:               ");
    printf("%#x\n", (unsigned int)e_entry);
}

int main(int argc, char *argv[])
{
    int fd, _read, _close;
    Elf64_Ehdr *file;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <filename>\n", argv[0]);
        exit(98);
    }

    file = malloc(sizeof(Elf64_Ehdr));
    if (file == NULL)
    {
        perror("malloc");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        free(file);
        exit(98);
    }

    _read = read(fd, file, sizeof(Elf64_Ehdr));
    if (_read == -1)
    {
        perror("read");
        free(file);
        close(fd);
        exit(98);
    }

    verify(file->e_ident);
    magic(file->e_ident);
    class(file->e_ident);
    data(file->e_ident);
    version(file->e_ident);
    osabi(file->e_ident);
    printf("  ABI Version:                       ");
    printf("%i\n", file->e_ident[EI_ABIVERSION]);
    type(file->e_type, file->e_ident);
    entry(file->e_entry, file->e_ident);

    free(file);

    _close = close(fd);
    if (_close == -1)
    {
        perror("close");
        exit(98);
    }

    return 0;
}
