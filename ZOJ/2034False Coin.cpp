/*ZJU 2034 False Coin
2003.12.18 By adai
00:00.01 404K*/

#include <cstdio>

using namespace std;

int main(void){
    long kase,t,count,p,len,num;
    long n,k,i,j;
    char test;
    scanf("%ld",&kase);
    for(t=0;t<kase;t++){
        if(t) printf("\n");
        scanf("%ld %ld",&n,&k);
        long* a=new long[n];
        for(i=0;i<n;i++){       //a[i]为0表示不确定 为1表示真coin 
            a[i]=0;            //为2表示可能偏轻 为3表示可能偏重 
        }
        for(i=0;i<k;i++){
            long* b=new long[n];
            for(j=0;j<n;j++){
                b[j]=0;
            }
            scanf("%ld",&p);
            len=p*2;
            long* c=new long[len];
            for(j=0;j<len;j++){
                scanf("%ld",&c[j]);
                b[c[j]-1]=1;
            }
            getchar();
            scanf("%c",&test);
            if(test=='='){
                for(j=0;j<n;j++){
                    if(b[j]==1){
                        a[j]=1;
                    }
                }
            }
            else if(test=='>'){
                for(j=0;j<n;j++){
                    if(b[j]==0) a[j]=1;
                }
                for(j=0;j<p;j++){
                    if(a[c[j]-1]==2) a[c[j]-1]=1;
                    else if(a[c[j]-1]==1) continue;
                    else a[c[j]-1]=3;
                }
                for(;j<len;j++){
                    if(a[c[j]-1]==3) a[c[j]-1]=1;
                    else if(a[c[j]-1]==1) continue;
                    else a[c[j]-1]=2;
                }
            }
            else{
                for(j=0;j<n;j++){
                    if(b[j]==0) a[j]=1;
                }
                for(j=0;j<p;j++){
                    if(a[c[j]-1]==3) a[c[j]-1]=1;
                    else if(a[c[j]-1]==1) continue;
                    else a[c[j]-1]=2;
                }
                for(;j<len;j++){
                    if(a[c[j]-1]==2) a[c[j]-1]=1;
                    else if(a[c[j]-1]==1) continue;
                    else a[c[j]-1]=3;
                }
            }
            delete []b;
            delete []c;
        }
        count=0;
        for(i=0;i<n;i++){
            if(a[i]!=1){
                count++;
                if(count==1) num=i;
                else break;
            }
        }
        if(count==1) printf("%ld\n",++num);
        else printf("0\n");
        delete []a;
    }
    return 0;
}
