/*ZJU 1760 Doubles
2003.11.21 By adai
00:00.00 376K*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    long a[15],t(0),i,j,temp,num(0);
    while(scanf("%ld",&temp)){
        if(temp==-1) break;
        if(temp==0){
            for(i=0;i<t;i++){
                for(j=0;j<t;j++){
                    if(a[j]==a[i]*2) num++;
                }
            }
            printf("%ld\n",num);
            num=t=0;
        }
        else{
            a[t++]=temp;
        }
    }
    return 0;
}
            
