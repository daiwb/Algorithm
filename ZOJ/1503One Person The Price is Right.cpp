//ZJU 1503 One Person "The Price is Right"
//2003.08.31 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int num[31][31]={0};
    int kase=1,g,l,i,j;
    for(i=0;i<31;i++) num[i][0]=i;
    num[0][1]=0;
    for(i=1;i<31;i++){
        for(j=1;j<=i;j++) num[i][j]=1+num[i-1][j-1]+num[i-1][j];
        for(j=i+1;j<31;j++) num[i][j]=num[i][i];
    }
    while(cin>>g>>l&&!(g==0&&l==0)){
        cout<<"Case "<<kase++<<": "<<num[g][l]<<endl;
    }
    return 0;
}
