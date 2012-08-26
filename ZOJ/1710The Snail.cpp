/*ZJU 1710 The Snail
2003.11.30 By adai
00:00.00 440K*/

#include <iostream>

using namespace std;

int main(void){
    double h,u,d,f,t;
    long day;
    while(cin>>h>>u>>d>>f&&h!=0){
        f=u*f/100;
        day=0;
        t=0;
        while(1){
            day++;
            t+=u;
            if(t>h){
                cout<<"success on day "<<day<<endl;
                break;
            }
            t-=d;
            if(t<0){
                cout<<"failure on day "<<day<<endl;
                break;
            }
            u-=f;
            if(u<0) u=0;
        }
    }
    return 0;
}
            
        
