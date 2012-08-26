/*ZJU 2001 Adding Reversed Numbers
2003.12.10 By adai
00:00.03 384K*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void){
    char a[100],b[100],c[100];
    long num,i,j;
    scanf("%ld",&num);
    while(num--){
        scanf("%s %s",a,b);
        long lena,lenb,len,add(0),temp;
        lena=strlen(a);
        lenb=strlen(b);
        len=lena<lenb?lena:lenb;
        for(i=0;i<len;i++){
            temp=a[i]-'0'+b[i]-'0'+add;
            if(temp>=10){
                c[i]=temp-10+'0';
                add=1;
            }
            else{
                c[i]=temp+'0';
                add=0;
            }
        }
        if(lena<lenb){
            for(;i<lenb;i++){
                temp=b[i]-'0'+add;
                if(temp>=10){
                    c[i]=temp-10+'0';
                    add=1;
                }
                else{
                    c[i]=temp+'0';
                    add=0;
                }
            }
        }
        else{
            for(;i<lena;i++){
                temp=a[i]-'0'+add;
                if(temp>=10){
                    c[i]=temp-10+'0';
                    add=1;
                }
                else{
                    c[i]=temp+'0';
                    add=0;
                }
            }    
        }
        if(add==1){
            c[i]='1';
            len=i+1;
        }
        else{
            len=i;
        }
        i=0;
        while(c[i]=='0') i++;
        j=len-1;
        while(c[j]=='0') j--;
        long t;
        for(t=i;t<=j;t++) printf("%c",c[t]);
        printf("\n");
    }
    return 0;
}
        
