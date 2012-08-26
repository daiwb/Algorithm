//ZJU 1394 Polar Explorer
//2003.07.31 BY ADAI

#include <iostream>
#include <string>

using namespace std;

int main(void){
    char ch[11];
    double pi=3.14159;
    double r,gas,angle,dis,dis2;
    while(cin>>ch&&strcmp(ch,"ENDOFINPUT")!=0){
        cin>>r>>gas>>angle;
        cin>>ch;
        if(angle>180) angle=360-angle;
        angle=angle/180*pi;
        dis=2*angle*r;
        dis2=gas*5;
        if(dis2>=dis) cout<<"YES "<<(int)(gas-dis/5)<<endl;
        else cout<<"NO "<<(int)(gas*5)<<endl;
        
    }
    return 0;
}
        
        
    
