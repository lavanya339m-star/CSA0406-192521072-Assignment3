#include <stdio.h>
#define N 12
#define F 3
int main(void){
    int ref[N]={7,0,1,2,0,3,0,4,2,3,0,3}, frame[F]={-1,-1,-1}, bit[F]={0},hand=0,faults=0;
    for(int i=0;i<N;i++){
        int hit=-1;for(int j=0;j<F;j++)if(frame[j]==ref[i])hit=j;
        if(hit>=0){bit[hit]=1;continue;}
        faults++;
        while(bit[hand]){bit[hand]=0;hand=(hand+1)%F;}
        frame[hand]=ref[i];bit[hand]=1;hand=(hand+1)%F;
    }
    printf("Clock demo faults=%d (reference string length=%d, frames=%d)\n",faults,N,F);
    return 0;
}
