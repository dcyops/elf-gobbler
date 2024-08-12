#ifndef INSPECT_FILE_H
#define INSPECT_FILE_H

#if defined(__LP64__)
#define ElfW(type) Elf64_ ## type
#else
#define ElfW(type) Elf32_ ## type
#endif

#include <elf.h>

void
read_file_header(
	const char *
	);



#endif /* INSPECT_FILE_H */
