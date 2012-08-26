/*ZJU 1814 Candy Sharing Game
2003.11.22 By adai
00:00.00 404K*/

#include <cstdio>

int main(void){
    long n,i,temp;
    while(scanf("%ld",&n)&&n!=0){
        long* candy=new long[n];
        for(i=0;i<n;i++){
            scanf("%ld",&candy[i]);
        }
        long count(0),sign;
        while(1){
            count++;
            temp=candy[n-1];
            for(i=n-1;i>=1;i--){
                candy[i]=candy[i]/2+candy[i-1]/2;
            }
            candy[0]=candy[0]/2+temp/2;
            for(i=0;i<n;i++){
                if(candy[i]%2!=0) candy[i]+=1;
            }
            sign=1;
            temp=candy[0];
            for(i=1;i<n-1;i++){
                if(candy[i]!=temp){
                    sign=0;
                    break;
                }
            }
            if(sign==1){
                printf("%ld %ld\n",count,candy[0]);
                break;
            }
        }
    }
    return 0;
}
            
