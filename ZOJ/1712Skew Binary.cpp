/*ZJU 1712 Skew Binary
2003.10.27 BY adai
00:00.00 444K*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    char input[50];
    int len,i;
    long num;
    while(cin>>input){
        if(strcmp(input,"0")==0) break;
        len=strlen(input);
        num=0;
        for(i=len-1;i>=0;i--){
            num+=(pow(2,len-i+0.0)-1)*(input[i]-'0');
        }
        cout<<num<<endl;
    }
    return 0;
}
            
