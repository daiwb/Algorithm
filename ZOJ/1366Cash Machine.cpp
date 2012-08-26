//ZJU 1366 Cash Machine
//2003.09.10 BY adai

#include <iostream>

using namespace std;

int main(void){
    long cash,i,j,m;
    while(cin>>cash){
        int* a=new int[cash+1];
        for(i=1;i<=cash;i++) a[i]=0;
        a[0]=1;
        int num;
        cin>>num;
        int n,d;
        for(i=0;i<num;i++){
            cin>>n>>d;
            if(a[cash]==1) continue;
            for(j=cash-1;j>=0;j--){
                if(a[cash]==1) break;
                if(a[j]==1){
                    for(m=1;m<=n;m++){
                        if(j+m*d>cash) break;
                        a[j+m*d]=1;
                    }
                }
            }
        }
        for(i=cash;i>=0;i--){
            if(a[i]==1){
                cout<<i<<endl;
                break;
            }
        }
        delete []a;
    }
    return 0;
}
                
                
