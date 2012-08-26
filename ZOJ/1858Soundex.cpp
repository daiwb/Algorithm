/*ZJU 1858 Soundex
2003.12.15 By adai
00:00.00 376K*/

#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    char change[27]="*123*12**22455*12623*1*2*2";
    char input[21];
    int i;
    while(scanf("%s",input)!=EOF){
        int len;
        char temp,prev='0';
        len=strlen(input);
        for(i=0;i<len;i++){
            temp=change[input[i]-'A'];
            if(temp=='*'){
                prev='0';
                continue;
            }
            if(temp==prev) continue;
            printf("%c",temp);
            prev=temp;
        }
        printf("\n");
    }
    return 0;
}
