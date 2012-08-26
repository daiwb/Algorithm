//ZJU 1005 Jugs
//2003.08.09 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int ca,cb,n,a,b,i,j,tmp;
    while(cin>>ca>>cb>>n){
        a=b=0;
        while(1){
            if(a==0){
                cout<<"fill A"<<endl;
                a=ca;
            }
            i=a;
            j=cb-b;
            tmp=i<j?i:j;
            cout<<"pour A B"<<endl;
            a-=tmp;
            b+=tmp;
            if(b==n){
                cout<<"success"<<endl;
                break;
            }
            if(b==cb){
                cout<<"empty B"<<endl;
                b=0;
            }
        }
    }
    return 0;
}
