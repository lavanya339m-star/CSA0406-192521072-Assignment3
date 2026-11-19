#include <stdio.h>
int main(void) {
    int *p = NULL;
    puts("About to access an invalid address (expected SIGSEGV).");
    fflush(stdout);
    *p = 42;
    return 0;
}
