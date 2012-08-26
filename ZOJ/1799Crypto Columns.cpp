/*ZJU 1799 Crypto Columns
2003.11.22 By adai
00:00.00 432K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    long row,col,i,j;
    char key[11];
    char text[101];
    while(cin>>key){
        if(strcmp(key,"THEEND")==0) break;
        cin>>text;
        row=strlen(key);
        col=strlen(text)/row;
        int* a=new int[row];
        int* b=new int[row];
        int num=0;
        for(i=0;i<26;i++){
            for(j=0;j<row;j++){
                if(key[j]=='A'+i) a[num++]=j;
            }
        }
        num=0;
        for(i=0;i<row;i++){
            for(j=0;j<row;j++){
                if(a[j]==i) b[num++]=j;
            }
        }
        for(i=0;i<col;i++){
            for(j=0;j<row;j++){
                cout<<text[b[j]*col+i];
            }
        }
        cout<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
