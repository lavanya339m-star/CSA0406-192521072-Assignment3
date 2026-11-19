#include <stdio.h>
int main(void){
    double disk=4.0; int n=6;
    printf("RAID0 %.1f TB\n",n*disk);
    printf("RAID1 (3 mirror pairs) %.1f TB\n",(n/2)*disk);
    printf("RAID5 %.1f TB\n",(n-1)*disk);
    printf("RAID6 %.1f TB\n",(n-2)*disk);
    printf("RAID10 (3 mirror pairs) %.1f TB\n",(n/2)*disk);
    return 0;
}
