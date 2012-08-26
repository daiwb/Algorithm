/*ZJU 1212 Mountain Landscape
2003.08.23 BY ADAI*/

#include <stdio.h>
#include <math.h>
#define pi acos(-1)

int main(void){
    double h,len;
    char input[1000];
    char ch;
    double a[7];
    double d[6];
    int i,n;
    printf("Problem 6 by team x\n");
    while(scanf("%lf",&a[0])!=EOF){
        ch=getchar();
        i=0;
        while(ch!='\n')
        {
            scanf("%lf %lf%c",&d[i],&a[i+1],&ch); 
            i++; 
        } 
        n=i; 
        printf("\n");
        h=len=0;
        for(i=0;i<n+1;i++) a[i]=a[i]*pi/180;
        for(i=0;i<n;i++){
            len+=d[i]*cos(a[i]);
            h+=d[i]*sin(a[i]);
            printf("Altitude of peak %d =%7.1f\n",i+1,h);
        }
        len+=h/tan(-a[n]);
        printf("Pipeline length    =%7.1f\n",len);
    }
    printf("End of problem 6 by team x\n");
    return 0;
}
