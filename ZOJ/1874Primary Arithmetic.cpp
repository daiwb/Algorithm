/*ZJU 1874 Primary Arithmetic
2003.12.03 By adai
00:00.00 436K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char a[10],b[10];
    int i,num,add;
    while(cin>>a>>b){
        if(strcmp(a,"0")==0&&strcmp(b,"0")==0) break;
        int lena,lenb,len;
        lena=strlen(a);
        lenb=strlen(b);
        len=lena<lenb?lena:lenb;
        num=add=0;
        for(i=0;i<len;i++){
            if(a[lena-1-i]-'0'+b[lenb-1-i]-'0'+add>=10){
                add=1;
                num++;
            }
            else add=0;
        }
        if(lena<lenb){
            for(;i<lenb;i++){
                if(b[lenb-1-i]-'0'+add>=10){
                    add=1;
                    num++;
                }
                else add=0;
            }
        }
        else{
            for(;i<lena;i++){
                if(a[lena-1-i]-'0'+add>=10){
                    add=1;
                    num++;
                }
                else add=0;
            }
        }
        if(num==0) cout<<"No carry operation."<<endl;
        else if(num==1) cout<<"1 carry operation."<<endl;
        else cout<<num<<" carry operations."<<endl;
    }
    return 0;
}
