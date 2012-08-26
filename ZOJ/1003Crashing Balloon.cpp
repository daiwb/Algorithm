//ZJU 1003 1003Crashing Balloon
//2003.08.08 BY ADAI

#include <iostream>

using namespace std;

long win,i;

int main(void){
    long big,sma;
    long judge(long big,long sma,long n);
    while(cin>>big>>sma){
        if(big<sma){
            long temp=big;
            big=sma;
            sma=temp;
        }
        win=0;//win 0:small wins 1:big wins
        i=0;
        judge(big,sma,2);
        if(win==0&&i==1) cout<<sma<<endl;
        else cout<<big<<endl;
    }
    return 0;
}

long judge(long big,long sma,long n){
    if(big==1&&sma==1){
        win=1;
        return 0;
    }
    if(n>100){
        if(sma==1) i=1;
        return 0;
    }
    if(big<n&&sma<n) return 0;
    if(big%n==0) judge(big/n,sma,n+1);
    if(sma%n==0) judge(big,sma/n,n+1); 
    judge(big,sma,n+1);
    return 0;
}
