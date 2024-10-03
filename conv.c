#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <libelf.h>
#include <gelf.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <elf-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the ELF file
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Initialize the ELF library
    if (elf_version(EV_CURRENT) == EV_NONE)
    {
        fprintf(stderr, "ELF library initialization failed: %s\n", elf_errmsg(-1));
        close(fd);
        return EXIT_FAILURE;
    }

    // Begin reading the ELF file
    Elf *elf = elf_begin(fd, ELF_C_RDWR, NULL);
    if (elf == NULL)
    {
        fprintf(stderr, "elf_begin failed: %s\n", elf_errmsg(-1));
        close(fd);
        return EXIT_FAILURE;
    }

    // Retrieve the number of program headers
    size_t phnum;
    if (elf_getphdrnum(elf, &phnum) != 0)
    {
        fprintf(stderr, "elf_getphdrnum failed: %s\n", elf_errmsg(-1));
        elf_end(elf);
        close(fd);
        return EXIT_FAILURE;
    }

    // Iterate over the program headers
    GElf_Phdr phdr;
    int modified = 0;
    for (size_t i = 0; i < phnum; ++i)
    {
        if (gelf_getphdr(elf, i, &phdr) == NULL)
        {
            fprintf(stderr, "gelf_getphdr failed: %s\n", elf_errmsg(-1));
            elf_end(elf);
            close(fd);
            return EXIT_FAILURE;
        }

        // Modify a PT_NOTE or other segment (use PT_NOTE for this example)
        if (phdr.p_type == PT_NOTE)
        {
            printf("Found PT_NOTE segment at index %zu, modifying permissions...\n", i);
            phdr.p_flags |= PF_W | PF_X; // Add Write and Execute permissions

            // Write the modified program header back to the ELF file
            if (gelf_update_phdr(elf, i, &phdr) == 0)
            {
                fprintf(stderr, "gelf_update_phdr failed: %s\n", elf_errmsg(-1));
                elf_end(elf);
                close(fd);
                return EXIT_FAILURE;
            }

            modified = 1; // Mark the segment as modified
            break;
        }
    }

    if (!modified)
    {
        printf("No PT_NOTE segment found.\n");
    }
    else
    {
        printf("PT_NOTE segment successfully modified.\n");

        // Ensure changes are flushed to disk
        if (elf_update(elf, ELF_C_WRITE) < 0)
        {
            fprintf(stderr, "elf_update failed: %s\n", elf_errmsg(-1));
            elf_end(elf);
            close(fd);
            return EXIT_FAILURE;
        }
    }

    // Cleanup
    elf_end(elf);
    close(fd);

    return modified ? EXIT_SUCCESS : EXIT_FAILURE;
}
