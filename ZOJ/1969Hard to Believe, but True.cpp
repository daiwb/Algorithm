/*ZJU 1969 Hard to Believe, but True!
2003.12.11 By adai
00:00.01 436K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char input[85];
    int i,j,lena,lenb,lenc,len,min;
    while(cin>>input){
        if(strcmp(input,"0+0=0")==0){
            cout<<"True"<<endl;
            break;
        }
        char a[15],b[15],c[15],d[15];
        i=j=0;
        while(input[i]!='+'){
            a[j++]=input[i++];
        }
        lena=j;
        i++;
        j=0;
        while(input[i]!='='){
            b[j++]=input[i++];
        }
        lenb=j;
        i++;
        j=0;
        while(input[i]!='\0'){
            c[j++]=input[i++];
        }
        lenc=j;
        min=lena<lenb?lena:lenb;
        int add(0),temp;
        for(i=0;i<min;i++){
            temp=a[i]-'0'+b[i]-'0'+add;
            if(temp>=10){
                d[i]=temp-10+'0';
                add=1;
            }
            else{
                d[i]=temp+'0';
                add=0;
            }
        }
        if(lena<lenb){
            for(;i<lenb;i++){
                temp=b[i]-'0'+add;
                if(temp>=10){
                    d[i]=temp-10+'0';
                    add=1;
                }
                else{
                    d[i]=temp+'0';
                    add=0;
                }
            }
        }
        else{
            for(;i<lena;i++){
                temp=a[i]-'0'+add;
                if(temp>=10){
                    d[i]=temp-10+'0';
                    add=1;
                }
                else{
                    d[i]=temp+'0';
                    add=0;
                }
            }
        }
        if(add==1){
            d[i]='1';
            len=i+1;
        }
        else{
            len=i;
        }
        for(;len>=2;len--){
            if(d[len-1]!='0') break;
        }
        if(lenc<len){
            cout<<"False"<<endl;
            continue;
        }
        int sign=1;
        for(i=0;i<len;i++){
            if(c[i]!=d[i]){
                sign=0;
                break;
            }
        }
        if(sign==0){
            cout<<"False"<<endl;
            continue;
        }
        for(;i<lenc;i++){
            if(c[i]!='0'){
                sign=0;
                break;
            }
        }
        if(sign==0) cout<<"False"<<endl;
        else cout<<"True"<<endl;
    }
    return 0;
}
