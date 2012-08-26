//ZJU 1047 Image Perimeters
//2003.08.04 BY ADAI

#include <iostream>

using namespace std;

int a[22][22];
int movex[8]={-1,-1,-1,0,1,1,1,0};
int movey[8]={-1,0,1,1,1,0,-1,-1};

void sel(int x,int y){
    a[x][y]=2;
    int i,tempi,tempj;
    for(i=0;i<8;i++){
        tempi=x+movex[i];
        tempj=y+movey[i];
        if(a[tempi][tempj]==1) sel(tempi,tempj); 
    }
}

int main(void){
    int i,j;
    int row,col,x,y,c;
    while(cin>>row>>col>>x>>y&&!(row==0&&col==0&&x==0&&y==0)){
        char* temp=new char[col+1];
        for(i=1;i<=row;i++){
            cin>>temp;
            for(j=1;j<=col;j++){
                if(temp[j-1]=='.') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        delete []temp;
        for(i=0;i<=col+1;i++) a[0][i]=a[row+1][i]=0;
        for(i=0;i<=row+1;i++) a[i][0]=a[i][col+1]=0;
        sel(x,y);
        c=0;
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                if(a[i][j]!=2) continue;
                if(a[i-1][j]==0) c++;
                if(a[i+1][j]==0) c++;
                if(a[i][j-1]==0) c++;
                if(a[i][j+1]==0) c++;
                
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
        
                
        
        
        
        
        
