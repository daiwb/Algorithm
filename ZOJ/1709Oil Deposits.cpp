/*ZJU 1709 Oil Deposits
2003.10.29 By adai
00:00.01 476K*/

#include <iostream>

using namespace std;

int oil[102][102];

int num;

int find(int i,int j){
    oil[i][j]=2;
    if(oil[i-1][j]==1) find(i-1,j);
    if(oil[i-1][j+1]==1) find(i-1,j+1);
    if(oil[i][j+1]==1) find(i,j+1);
    if(oil[i+1][j+1]==1) find(i+1,j+1);
    if(oil[i+1][j]==1) find(i+1,j);
    if(oil[i+1][j-1]==1) find(i+1,j-1);
    if(oil[i][j-1]==1) find(i,j-1);
    if(oil[i-1][j-1]==1) find(i-1,j-1);
}

int main(void){
    int m,n,i,j;
    while(cin>>m>>n&&m!=0){
        for(i=0;i<102;i++){
            for(j=0;j<102;j++){
                oil[i][j]=0;
            }
        }
        char temp[101];
        for(i=1;i<=m;i++){
            cin>>temp;
            for(j=0;j<n;j++){
                if(temp[j]=='@') oil[i][j+1]=1;
            }
        }
        num=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(oil[i][j]==1) num++;
                else continue;
                find(i,j);
            }
        }
        cout<<num<<endl;
    }
    return 0;
}

