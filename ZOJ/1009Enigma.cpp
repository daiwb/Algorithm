//ZJU 1009 Enigma
//2003.09.05 BY ADAI

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int i,j,m,n,kase=0,t,p,q;
    int change[3][26];
    char temp[100000];
    int convert[3];
    while(cin>>m&&m!=0){
        if(kase) cout<<endl;
        cout<<"Enigma "<<++kase<<":"<<endl;
        for(i=0;i<3;i++){
            cin>>temp;
            for(j=0;j<m;j++) change[i][temp[j]-'A']=j-(temp[j]-'A');
        }
        cin>>n;
        while(n--){
            cin>>temp;
            convert[0]=convert[1]=convert[2]=0;
            int length=strlen(temp);
            for(i=0;i<length;i++){
                /*convert[0]=i%m;
                convert[1]=(i/m)%m;
                convert[2]=(i/(m*m))%m;*/
                t=temp[i]-'A';
                for(p=2;p>=0;p--){
                    t+=change[p][(t-convert[p]+m)%m];
                    t=(t+m)%m;
                } 
                cout<<char(t+'a');
                convert[0]++;
                if(convert[0]%m==0){
                    convert[0]=0;
                    convert[1]++;
                    if(convert[1]%m==0){
                        convert[1]=0;
                        convert[2]++;
                        if(convert[2]%m==0) convert[2]=0;
                    }
                }           
            }
            cout<<endl;
        }
    }
    return 0;
}
