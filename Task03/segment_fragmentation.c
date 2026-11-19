#include <stdio.h>
#include <stdlib.h>
int main(void) {
    unsigned seed=42; srand(seed);
    int sizes[20], total=0;
    for(int i=0;i<20;i++){ sizes[i]=1+rand()%100; total+=sizes[i]; }
    printf("20 generated segment sizes (units):\n");
    for(int i=0;i<20;i++) printf("%d%s",sizes[i],i==19?"\n":" ");
    printf("Total requested segment space=%d units\n",total);
    puts("To calculate external fragmentation, record free holes after your load/remove sequence.");
    return 0;
}
