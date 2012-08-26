/*ZJU 1938 Binomial Showdown
2003.12.11 By adai
00:00.00 436K*/

#include <iostream>

using namespace std;

int main(void){
    long n,k,i;
    while(cin>>n>>k){
        if(n==0&&k==0) break;
        double num=1;
        if(k>n/2) k=n-k;
        for(i=1;i<=k;i++){
            num*=(double)(n-k+i)/i*1.000000000001;
        }
        cout<<(long)num<<endl;
    }
    return 0;
}
        
