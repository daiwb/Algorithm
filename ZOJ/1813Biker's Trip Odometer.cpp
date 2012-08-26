/*ZJU 1813 Biker's Trip Odometer
2003.11.24 By adai
00:00.00 376K*/

#include <cstdio>

using namespace std;

int main(void){
    float d,dis,mph,pi=3.1415927,r,t;
    long kase=1;
    while(1){
        scanf("%f %f %f",&d,&r,&t);
        if(r==0) break;
        dis=pi*d*r/(12*5280);
        mph=dis/t*3600;
        printf("Trip #%ld: %.2f %.2f\n",kase++,dis,mph);
    }
    return 0;
}
        
