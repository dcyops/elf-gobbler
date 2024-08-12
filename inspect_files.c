#include "./inspect_files.h"
#include <stdio.h>

void
read_file_header(const char *file)
{
    ElfW(Ehdr) header;

	/* Open file in binary mode */
    FILE *fp = fopen(file, "rb");
    if (!fp) {
		return;
    }

    if (fread(&header, sizeof(header), 1, fp) != 1) {
        fclose(fp);
        return;
    }

    if (header.e_ident[0] == 0x7f &&
        header.e_ident[1] == 'E' &&
        header.e_ident[2] == 'L' &&
        header.e_ident[3] == 'F') {
        printf("<%s> is an ELF file", file);
    } else {
		printf("<%s> is not an ELF file\n", file);
	}

	fclose(fp);

    return;
}

