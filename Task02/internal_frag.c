#include <stdio.h>
#include <stdlib.h>
int main(void) {
    const int pages[] = {1024, 4096, 2*1024*1024};
    unsigned seed = 42;
    srand(seed);
    for (int k = 0; k < 3; k++) {
        long long total = 0;
        for (int i = 0; i < 100; i++) {
            int size = 1 + rand() % (8*1024*1024);
            long long alloc = ((size + pages[k] - 1LL) / pages[k]) * pages[k];
            total += alloc - size;
        }
        printf("page_size=%d total_internal_fragmentation=%lld bytes\n", pages[k], total);
    }
    return 0;
}
