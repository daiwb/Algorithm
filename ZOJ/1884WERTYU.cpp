/*ZJU 1884 WERTYU
2003.12.03
00:00.00 432K*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    char a[]="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    char b[]="~1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    char input[100];
    long i,j;
    while(gets(input)){
        long len=strlen(input);
        for(i=0;i<len;i++){
            if(input[i]==' ') cout<<" ";
            else{
                for(j=0;j<43;j++){
                    if(a[j]==input[i]){
                        cout<<b[j];
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
