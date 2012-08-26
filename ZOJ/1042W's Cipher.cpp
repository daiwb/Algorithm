//2003.07.28 by adai

#include <iostream>

using namespace std;

int main(void){
    int i,j;
    int k[3];
    char out[85];
    char a[3][85];
    int b[3][85];
    int c[3];
    while(cin>>k[0]>>k[1]>>k[2]&&!(k[0]==0&&k[1]==0&&k[2]==0)){
        cin>>out;
        c[0]=c[1]=c[2]=0;
        for(i=0;out[i]!='\0';i++){
            if(out[i]>='a'&&out[i]<='i'){
                a[0][c[0]]=out[i];
                b[0][c[0]++]=i;
            }
            else if(out[i]>='j'&&out[i]<='r'){
                a[1][c[1]]=out[i];
                b[1][c[1]++]=i;
            }
            else{
                a[2][c[2]]=out[i];
                b[2][c[2]++]=i;
            }
        }
        for(i=0;i<3;i++){
            if(c[i]==0) continue;
            k[i]%=c[i];
            char* temp=new char[c[i]];
            for(j=0;j<c[i];j++){
                temp[(j+k[i])%c[i]]=a[i][j];
            }
            for(j=0;j<c[i];j++) out[b[i][j]]=temp[j];
            delete []temp;
        }
        for(i=0;out[i]!='\0';i++) cout<<out[i];
        cout<<endl;
    }
    return 0;
}
        
            
            
            
        
        
