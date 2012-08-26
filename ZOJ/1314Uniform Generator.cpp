#include <stdio.h>

int main(void){
    long s,m,i,j,t,c;
    long a[100000];
    while(scanf("%d %d",&s,&m)!=EOF){
        printf("%10d%10d",s,m);
        t=0;
        c=1;
        for(i=0;i<m;i++) a[i]=0;
        i=0;
        while(1){
            if(a[i]==1){
                c=0;
                break;
            }
            a[i]=1;
            t++;
            if(t==m) break;
            i+=s;
            i%=m;
        }
        if(c==1) printf("    Good Choice\n\n");
        else printf("    Bad Choice\n\n");
    }
    return 0;
}
        
