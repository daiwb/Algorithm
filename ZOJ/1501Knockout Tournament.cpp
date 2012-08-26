//ZJU 1501 Knockout Tournament
//2003.07.20 BY ADAI

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int n,m,i,j,t,high,low,temp,s,size;
    s=0;
    while(cin>>n&&n!=0){
        if(s==1) cout<<endl;
        s=1;
        size=(int)pow(2.0,n+0.0);
        int* num=new int[size];
        for(i=n-1;i>=0;i--){
            for(j=(int)pow(2.0,i+0.0);j<(int)pow(2.0,i+1.0);j++) cin>>num[j];
        }
        cin>>m;
        while(m--){
            high=low=0;
            cin>>t;
            temp=t;
            j=((int)pow(2.0,n+0.0)+t-1)/2;
            while(j>0){
                if(num[j]!=temp){
                    temp=num[j];
                    high++;
                }
                j/=2;
            }
            high++;
            temp=t;
            j=((int)pow(2.0,n+0.0)+t-1)/2;
            while(j>0){
                if(num[j]!=temp) break;
                low++;
                j/=2;
            }
            low=(int)pow(2.0,low+0.0)-1;
            low=(int)pow(2.0,n+0.0)-low;
            cout<<"Player "<<t<<" can be ranked as high as "<<high<<" or as low as "<<low<<"."<<endl;
        }
        delete []num;
    }
    return 0;
}
                
                
            
            
            
