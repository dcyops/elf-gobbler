#ifndef FIND_FILES_H
#define FIND_FILES_H

#define _XOPEN_SOURCE 1			/* Required under GLIBC for nftw() */
#define _XOPEN_SOURCE_EXTENDED 1	/* Same */

#include <dirent.h>
#include <stdlib.h>
#include <ftw.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#define SPARE_FDS 5

/* init ntftw */
int
file_info(
    const char *,
	const struct stat *,
	int flag,
	struct FTW *
	);

int
init_ntftw(
	int argc,
	char *argv[]
	);


#endif /* FIND_FILES_H */
