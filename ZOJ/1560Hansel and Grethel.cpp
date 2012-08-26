//ZJU 1560 Hansel and Grethel
//2003.08.24 BY ADAI

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
    int kase;
    double a[2],b[2],x,y;
    int angel[2];
    double pi=acos(0.0+-1);
    cin>>kase;
    while(kase--){
        cin>>a[0]>>b[0]>>angel[0];
        cin>>a[1]>>b[1]>>angel[1];
        angel[0]=90-angel[0];
        angel[1]=90-angel[1];
        if(fabs(0.0+angel[0])==90||fabs(0.0+angel[1])==90){
            if(fabs(0.0+angel[0])==90){
                x=a[0];
                y=b[1]+tan(angel[1]*pi/180)*(x-a[1]);
            }
            else{
                x=a[1];
                y=b[0]+tan(angel[0]*pi/180)*(x-a[0]);
            }
        }
        else{
            x=(b[0]-b[1]+a[1]*tan(angel[1]*pi/180)-a[0]*tan(angel[0]*pi/180))/
            (tan(angel[1]*pi/180)-tan(angel[0]*pi/180));
            y=b[1]+tan(angel[1]*pi/180)*(x-a[1]);
        }
        cout<<setiosflags(ios::fixed)<<setprecision(4)<<x<<" "<<y<<endl;
    }
    return 0;
}
        
                
                
                
            
        
