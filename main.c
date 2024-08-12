#include "./main.h"
#include "./find_files.h"

int
main(int argc, char *argv[]) {
    if (argc != 3) {
		usage(&argv[0]);
	}

	/* Search for files */
    init_ntftw(argc, argv);
       return 0;
}

void
usage(char *argv[])
{
	fprintf(stderr, "Usage: %s <path>\n", argv[0]);
	return;

}


