/*ZJU 1808 Immediate Decodability
2003.11.19 By adai
00:00.00 432K*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char code[8][11];
int kase(1),num(0),i,j,t,sign(0),lena,lenb,len;
char temp[11];

void print(){
    for(i=1;i<num;i++){
        lena=strlen(code[i]);
        for(j=0;j<i;j++){
            lenb=strlen(code[j]);
            len=lena<lenb?lena:lenb;
            for(t=0;t<len;t++){
                if(code[i][t]!=code[j][t]){
                    break;
                }
            }
            if(t==len){
                sign=1;
                break;
            }
        }
        if(sign==1) break;
    }
    if(sign==0){
        printf("Set %d is immediately decodable\n",kase++);
    }
    else{
        printf("Set %d is not immediately decodable\n",kase++);
    }
    sign=0;
    num=0;
}

int main(void){
    while(cin>>temp){
        if(strcmp(temp,"9")==0){
            print();
        }
        else{
            strcpy(code[num++],temp);
        }
    }
    return 0;
}


            
            
