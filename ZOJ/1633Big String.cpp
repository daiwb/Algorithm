//ZJU 1633 Big String
//2003.09.06 BY adai

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#ifdef WIN32 
typedef __int64 i64; 
#else 
typedef long long i64; 
#endif 

int main(void){
    i64 fib[88];
    i64 num;
    int i;
    //num=pow(2,63)-1;
    //cout<<"num="<<num<<endl;
    fib[0]=3;
    fib[1]=7;
    for(i=2;i<88;i++){
        fib[i]=fib[i-1]+fib[i-2];
        //cout<<fib[i]<<endl;
    }
    while(cin>>num){
        i=87;
        while(1){
            if(num<=7){
                switch(long(num))
                {
                    case 1:cout<<"T"<<endl;break;
                    case 2:cout<<"."<<endl;break;
                    case 3:cout<<"T"<<endl;break;
                    case 4:cout<<"^"<<endl;break;
                    case 5:cout<<"_"<<endl;break;
                    case 6:cout<<"_"<<endl;break;
                    case 7:cout<<"^"<<endl;break;
                }
                break;
            }
            while(fib[i]>=num) i--;
            num-=fib[i];
        }
    }
    return 0;
}
