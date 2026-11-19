#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>
static double now(void){struct timespec t; clock_gettime(CLOCK_MONOTONIC,&t); return t.tv_sec+t.tv_nsec/1e9;}
int main(int argc,char **argv){
    size_t mb=argc>1?(size_t)strtoul(argv[1],0,10):256;
    size_t bytes=mb*1024*1024, page=(size_t)sysconf(_SC_PAGESIZE);
    volatile unsigned char *p=malloc(bytes); if(!p){perror("malloc");return 1;}
    struct rusage a,b; getrusage(RUSAGE_SELF,&a); double t=now();
    for(size_t i=0;i<bytes;i+=page)p[i]=(unsigned char)i;
    double seq=now()-t; getrusage(RUSAGE_SELF,&b);
    printf("sequential: %zu MB, %.6f s, minor_faults=%ld, major_faults=%ld\n",mb,seq,b.ru_minflt-a.ru_minflt,b.ru_majflt-a.ru_majflt);
    unsigned seed=7; srand(seed); getrusage(RUSAGE_SELF,&a); t=now();
    for(size_t i=0;i<bytes;i+=page){size_t n=(size_t)(rand()%(bytes/page))*page;p[n]++;}
    double rnd=now()-t; getrusage(RUSAGE_SELF,&b);
    printf("random: %.6f s, minor_faults=%ld, major_faults=%ld\n",rnd,b.ru_minflt-a.ru_minflt,b.ru_majflt-a.ru_majflt);
    free((void*)p); return 0;
}
