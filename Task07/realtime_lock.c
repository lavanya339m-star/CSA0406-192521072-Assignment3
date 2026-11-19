#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>
static double ns(struct timespec t){return t.tv_sec*1e9+t.tv_nsec;}
int main(int argc,char **argv){
    int lock=(argc>1 && argv[1][0]=='1'); size_t bytes=4*1024*1024;
    long pg=sysconf(_SC_PAGESIZE); char *p=malloc(bytes); if(!p){perror("malloc");return 1;}
    for(size_t i=0;i<bytes;i+=(size_t)pg)p[i]=1;
    if(lock && mlock(p,bytes)!=0){perror("mlock (check RLIMIT_MEMLOCK)");free(p);return 1;}
    struct timespec a,b; volatile unsigned long sum=0; double worst=0;
    for(int k=0;k<10000;k++){clock_gettime(CLOCK_MONOTONIC,&a);
        for(int j=0;j<100;j++)sum+=p[(size_t)(j*4096)%bytes];
        clock_gettime(CLOCK_MONOTONIC,&b);double dt=ns(b)-ns(a);if(dt>worst)worst=dt;}
    printf("locked=%d iterations=10000 observed_worst_loop=%.0f ns checksum=%lu\n",lock,worst,sum);
    if(lock)munlock(p,bytes);free(p);return 0;
}
