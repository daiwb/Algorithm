/*ZJU 2022 Factorial
2003.12.11 By adai
00:00.12 380K*/

#include <cstdio>

using namespace std;

int main(void){
    long kase,n,num;
    scanf("%ld",&kase);
    while(kase--){
        scanf("%ld",&n);
        num=0;
        while(n>=5){
            n/=5;
            num+=n;
        }
        printf("%ld\n",num);
    }
    return 0;
}
            
        
