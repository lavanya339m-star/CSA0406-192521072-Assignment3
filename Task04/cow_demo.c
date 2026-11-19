#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void){
    size_t n=64*1024*1024; char *p=malloc(n); if(!p){perror("malloc");return 1;}
    for(size_t i=0;i<n;i+=4096)p[i]=1;
    printf("parent pid=%d allocated and touched %zu MB\n",getpid(),n/1024/1024);
    pid_t child=fork();
    if(child<0){perror("fork");free(p);return 1;}
    if(child==0){for(size_t i=0;i<n;i+=4096)p[i]=2; puts("child wrote to every page (copy-on-write may allocate private copies)");_exit(0);}
    wait(NULL); puts("parent: child completed"); free(p); return 0;
}
