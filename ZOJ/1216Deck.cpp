/*2003.07.26 by adai*/

#include <stdio.h>

int main(void){
    long i,n;
    double num[100000];
    num[0]=0;
    for(i=1;i<=99999;i++){
        num[i]=num[i-1]+0.5/i;
    }
    printf("# Cards  Overhang\n");
    while(scanf("%d",&n)!=EOF) printf("%5d     %.3f\n",n,num[n]);
    return 0;
}
        
