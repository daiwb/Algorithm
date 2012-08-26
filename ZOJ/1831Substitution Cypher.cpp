/*ZJU 1831 Substitution Cypher
2003.12.05 By adai
00:00.00 432K*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    char a[80],b[80],text[80];
    int i,j,sign,len,l;
    gets(a);
    gets(b);
    puts(b);
    puts(a);
    len=strlen(a);
    while(gets(text)){
        l=strlen(text);
        for(i=0;i<l;i++){
            sign=0;
            for(j=0;j<len;j++){
                if(text[i]==a[j]){
                    cout<<b[j];
                    sign=1;
                    break;
                }
            }
            if(sign==0) cout<<text[i];
        }
        cout<<endl;
    }
    return 0;
}
        
        
        
