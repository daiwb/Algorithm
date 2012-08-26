/*ZJU 1730 Crazy Tea Party
2003.11.19 By adai
00:00.00 376K*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    long num,n,m;
    scanf("%ld",&num);
    while(num--){
        scanf("%ld",&n);
        m=n/2;
        printf("%ld\n",(2*m*m-2*m*n+n*n-n)/2);
    }
    return 0;
}
        
