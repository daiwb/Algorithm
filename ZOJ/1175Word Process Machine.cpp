/*ZJU 1175 Word Process Machine
2003.08.20 BY ADAI*/

#include <stdio.h>
#include <string.h>

int main(void){
    long kase,k,num,head,tail,i,j,quit,r,count;
    char a[40005];
    char temp[100005];
    scanf("%d",&kase);
    for(k=0;k<kase;k++){
        if(k) printf("\n");
        scanf("%d",&num);
        getchar();
        head=0;
        tail=-1;
        for(i=0;i<num;i++){
            gets(temp);
            for(j=0;temp[j]!='\0';j++) a[++tail]=temp[j]; 
        }
        quit=r=count=0;
        while(1){
            if(quit==1){
                printf("\n");
                break;
            }
            gets(temp);
            for(i=0;temp[i]!='\0';i++){
                if(temp[i]=='#'){
                    quit=1;
                    break;
                }
                if(temp[i]=='G'&&head<=tail){
                    if(r==0) printf("%c",a[head++]);
                    else printf("%c",a[tail--]);
                    count++;
                    if(count==80){
                        printf("\n");
                        count=0;
                    }
                }
                else if(temp[i]=='R') r=(r+1)%2;
            }
        }
    }
    return 0;
}
        
