//2003.07.26 by adai
#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
    int t,i,j,top,judge;
    while(scanf("%d", &t) && t != 0) {
        int* a=new int[t+1];
        int* b=new int[t+1];
        while(scanf("%d", &a[1]) && a[1] != 0) {
            for(i=2;i<=t;i++) scanf("%d", &a[i]);
            b[0]=0;
            j=top=judge=0;
            for(i=1;i<=t;i++){
                if(a[i]>b[top]){
                    while(1){
                        b[++top]=++j;
                        if(j==a[i]){
                            top--;
                            break;
                        }
                    }
                }
                else if(a[i]==b[top]){
                    top--;
                }
                else{
                    judge=1;
                    break;
                }
            }
            if (judge == 0) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
