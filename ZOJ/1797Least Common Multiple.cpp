/*ZJU 1797 Least Common Multiple
2003.11.27 By adai
00:00.16 5096K*/

#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
    long i,j,num(0),t,temp;
    long* prime=new long[100000];
    long* count=new long[100000];
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
    for(i=2;i<1000001;i++){
        if(a[i]==0) prime[num++]=i;
    }
    //printf("num=%ld\n",num);
    long kase,n,input,output;
    scanf("%ld",&kase);
    while(kase--){
        for(i=0;i<num;i++){
            count[i]=0;
        }
        scanf("%ld",&n);
        for(t=0;t<n;t++){
            scanf("%ld",&input);
            i=0;
            while(input>1){
                j=0;
                while(input%prime[i]==0){
                    input/=prime[i];
                    j++;
                }
                if(j>count[i]) count[i]=j;
                i++;
            }
        }
        output=1;
        for(i=0;i<num;i++){
            if(count[i]>0) output*=pow(prime[i]+0.0,count[i]+0.0);
        }
        printf("%ld\n",output);
    }
    delete []prime;
    delete []count;
    delete []a;
    return 0;
}
        
    
