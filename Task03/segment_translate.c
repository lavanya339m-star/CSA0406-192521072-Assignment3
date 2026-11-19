#include <stdio.h>
typedef struct { int base, limit; } Segment;
int main(void) {
    Segment st[]={{10000,4000},{20000,3000},{30000,2000}};
    int tests[][2]={{0,0},{0,3999},{0,4000},{1,0},{1,1500},{1,3000},{2,500},{2,1999}};
    for (int i=0;i<8;i++) {
        int s=tests[i][0], off=tests[i][1];
        printf("(%d,%d) -> ",s,off);
        if (s<0 || s>=3 || off<0 || off>=st[s].limit) puts("protection fault");
        else printf("physical %d\n",st[s].base+off);
    }
    return 0;
}
