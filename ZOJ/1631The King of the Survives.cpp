//ZJU 1631 The King of the Survives
//2003.08.21 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    char name[2][50];
    int armor[2],hp[2],power[2],amount[2],cool[2];
    int damage[2],time[2];
    while(cin>>name[0]){
        cin>>hp[0]>>armor[0]>>cool[0]>>amount[0]>>power[0];
        cin>>name[1];
        cin>>hp[1]>>armor[1]>>cool[1]>>amount[1]>>power[1];
        damage[0]=power[1]-armor[0];
        if(damage[0]<1) damage[0]=1;
        damage[0]*=amount[1];
        damage[1]=power[0]-armor[1];
        if(damage[1]<1) damage[1]=1;
        damage[1]*=amount[0];
        if(hp[0]%damage[0]==0) time[0]=cool[1]*hp[0]/damage[0];
        else time[0]=cool[1]*(hp[0]/damage[0]+1);
        if(hp[1]%damage[1]==0) time[1]=cool[0]*hp[1]/damage[1];
        else time[1]=cool[0]*(hp[1]/damage[1]+1);
        if(time[0]==time[1]) cout<<"All Die!"<<endl;
        else if(time[0]<time[1]) cout<<name[1]<<" Survive!"<<endl;
        else cout<<name[0]<<" Survive!"<<endl;
    }
    return 0;
}
        
        
        
        
