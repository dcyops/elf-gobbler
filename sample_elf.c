// Simple program with a large global array
#include <stdio.h>

// A large global array to inflate the segment size
char large_array[4096 * 20] = {0}; // 40KB array

int main() {
    printf("Hello, World!\n");
    return 0;
}
