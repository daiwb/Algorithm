/*ZJU 1905 Power Strings
2003.12.02 By adai
00:01.17 1416K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char* input=new char[1000001];
    int mark;
    while(cin>>input){
        if(strcmp(input,".")==0) break;
        mark=0;
        long len=strlen(input),row,col,i,j,sign;
        for(row=len;row>=2;row--){
            if(len%row!=0) continue;
            col=len/row;
            sign=1;
            for(i=1;i<row;i++){
                for(j=0;j<col;j++){
                    if(input[i*col+j]!=input[j]){
                        sign=0;
                        break;
                    }
                }
                if(sign==0) break;
            }
            if(sign==1){
                mark=1;
                cout<<row<<endl;
                break;
            }
        }
        if(mark==0) cout<<"1"<<endl;
    }
    delete []input;
    return 0;
}
                
            
        
        
