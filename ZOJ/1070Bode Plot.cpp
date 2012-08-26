/*2003.07.27 by adai*/

#include <stdio.h>
#include <math.h>

int main(void){
    float vs,r,c,vr,w,angle;
    int n;
    scanf("%f %f %f %d",&vs,&r,&c,&n);
    while(n--){
        scanf("%f",&w);
        angle=atan(1.0/(r*c*w));
        vr=r*c*w*vs*sin(angle);
        printf("%.3f\n",vr);
    }
    return 0;
}
        
