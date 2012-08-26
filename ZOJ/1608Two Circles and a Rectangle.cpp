#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    double a,b,r1,r2,temp,s,h;
    while(cin>>a>>b>>r1>>r2){
        if(a<b){
            temp=a;
            a=b;
            b=temp;
        }
        if(r1<r2){
            temp=r1;
            r1=r2;
            r2=temp;
        }
        if(r1*2>b){
            cout<<"No"<<endl;
            continue;
        }
        s=b-r1-r2;
        h=sqrt(pow(r1+r2,2)-pow(s,2));
        if(h+r1+r2>a) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}        
        
        
