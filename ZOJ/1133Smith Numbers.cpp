//ZJU 1133 Smith Numbers
//2003.07.28 by adai

#include <iostream>
#include <cmath>

using namespace std;

long sum(long n){
    long num=0;
    while(n>0){
        num+=n%10;
        n/=10;
    }
    return num;
}

bool IsPrime(long n){
    if(n==2) return 1;
    long i;
    for(i=2;i<=sqrt(n*1.0);i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(void){
    long count=0,i,j,num1,num2,temp,n,t;
    long prime[10000];
    j=0;
    for(i=2;i<100000;i++){
        if(IsPrime(i)) prime[j++]=i;
    }
    while(cin>>n&&n!=0){
        for(i=n+1;;i++){
            num1=sum(i);
            num2=0;
            temp=i;
            j=prime[0];
            for(t=0;j<=sqrt(temp*1.0);){
                while(temp%j==0){
                    num2+=sum(j);
                    temp/=j;
                }
                j=prime[++t];
            }
            if(temp==i) continue;
            if(temp>1) num2+=sum(temp);
            if(num1==num2){
                cout<<i<<endl;
                break;
            }
        }
    }   
    return 0;
}
