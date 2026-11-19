#include <stdio.h>
int main(void) {
    const double M=100.0, T=10.0, hit[]={0.80,0.95,0.99};
    for (int i=0;i<3;i++)
        printf("hit=%.0f%% EAT=%.2f ns\n", hit[i]*100, hit[i]*(T+M)+(1-hit[i])*(T+2*M));
    return 0;
}
