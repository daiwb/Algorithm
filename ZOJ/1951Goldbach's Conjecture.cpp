/*ZJU 1951 Goldbach's Conjecture
2003.12.03 By adai
00:00.33 4336K*/

#include <iostream>

using namespace std;

int main(void){
    long i,j,n;
    long* a=new long[1000001];
    for(i=0;i<1000001;i++) a[i]=0;
    a[1]=1;
    for(i=2;i<=500000;i++) a[i*2]=1;
    for(i=3;i<=500000;i+=2){
        if(a[i]==1) continue;
        for(j=3;i*j<=1000000;j+=2){
            a[i*j]=1;
        }
    }
    while(cin>>n&&n!=0){
        for(i=3;i<=n/2;i+=2){
            if(a[i]==0&&a[n-i]==0){
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                break;
            }
        }
    }
    delete []a;
    return 0;
}   
