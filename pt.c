#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <libelf.h>
#include <gelf.h>

#define SHELLCODE_SIZE 128 // Adjust size as needed

void
modify_elf(const char *binary)
{
    printf("This is a file");

    return;
}

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <elf-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    modify_elf(argv[1]);

    return 0;
}
