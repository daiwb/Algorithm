//ZJU 1628 Diamond
//2003.08.20

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    char temp[9];
    int i,j,r1,c1,r2,c2,num;
    char ch;
    while(cin>>temp){
        char game[8][8];
        for(i=0;i<8;i++) game[0][i]=temp[i];
        for(j=1;j<8;j++){
            cin>>temp;
            for(i=0;i<8;i++) game[j][i]=temp[i];
        }
        cin>>r1>>c1>>r2>>c2;
        if(r1<1||r1>8||c1<1||c1>8||r2<1||r2>8||c2<1||c2>8){
            cout<<"Illegal move!"<<endl;
            continue;
        }
        if(abs(r1-r2)+abs(c1-c2)!=1){
            cout<<"Illegal move!"<<endl;
            continue;
        }
        ch=game[r1-1][c1-1];
        game[r1-1][c1-1]=game[r2-1][c2-1];
        game[r2-1][c2-1]=ch;
        for(i=0;i<8;i++){
            num=1;
            ch=game[i][0];
            for(j=1;j<8;j++){
                if(game[i][j]==ch){
                    num++;
                    if(num==3) break;
                }
                else{
                    ch=game[i][j];
                    num=1;
                }
            }
            if(num==3) break;
        }
        if(num==3){
            cout<<"Ok!"<<endl;
            continue;
        }
        for(i=0;i<8;i++){
            num=1;
            ch=game[0][i];
            for(j=1;j<8;j++){
                if(game[j][i]==ch){
                    num++;
                    if(num==3) break;
                }
                else{
                    ch=game[j][i];
                    num=1;
                }
            }
            if(num==3) break;
        }
        if(num==3) cout<<"Ok!"<<endl;
        else cout<<"Illegal move!"<<endl;
    }
    return 0;
}
                    
        
        
        
        
