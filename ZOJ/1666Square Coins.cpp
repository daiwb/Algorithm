/*ZJU 1666 Square Coins
00:00.00 440K
2003.11.01 By adai*/

#include <iostream>
#include <cmath>

using namespace std;

long num;

int count(long n,long t){
    long j;
    if(n==0||t==1){
        num++;
        return 0;
    }
    for(j=0;j*t*t<=n;j++){
        count(n-j*t*t,t-1);
    }
    return 0;
}   

int main(void){
    long n,t;
    while(cin>>n&&n!=0){
        num=0;
        t=sqrt(n+0.0);
        count(n,t);
        cout<<num<<endl;
    }
    return 0;
}
    
