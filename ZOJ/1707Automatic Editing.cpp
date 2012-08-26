/*ZJU 1707 Automatic Editing
00:00.00 376K
2003.11.08 By adai*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void){
    char a[10][81],b[10][81];
    char text[260];
    int num,i,j,t,find,lena,lenb,head,tail; //head表示从text的哪儿开始搜索 
    while(scanf("%d",&num)){
        getchar();
        if(num==0) break;
        for(i=0;i<num;i++){
            gets(a[i]);
            gets(b[i]);
        }
        gets(text);
        tail=strlen(text)-1;
        for(t=0;t<num;t++){
            lena=strlen(a[t]);
            if(tail+1<lena) continue;
            lenb=strlen(b[t]);
            head=0;
            while(1){
                find=0;
                for(i=head;i<=tail-lena+1;i++){
                    if(a[t][0]!=text[i]) continue;
                    find=1;
                    for(j=i+1;j<i+lena;j++){
                        if(a[t][j-i]!=text[j]){
                            find=0;
                            break;
                        }
                    }
                    if(find==1) break;
                }
                if(find==0) break;
                if(lenb>lena){
                    for(j=tail+1;j>=i+lena;j--){
                        text[j-lena+lenb]=text[j];
                    }
                }
                else if(lenb<lena){
                    for(j=i+lena;j<=tail+1;j++){
                        text[j-lena+lenb]=text[j];
                    }
                }
                tail+=lenb-lena;
                for(j=i;j<i+lenb;j++){
                    text[j]=b[t][j-i];
                }
                head=i+1-lena;
                if(head<0) head=0;
            }
        }
        puts(text);
    }
    return 0;
}
                
        
        
