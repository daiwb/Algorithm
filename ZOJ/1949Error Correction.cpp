/*ZJU 1949 Error Correction
2003.12.03 By adai
00:00.02 476K*/

#include <iostream>

using namespace std;

int main(void){
    int n,i,j;
    int mat[100][100];
    while(cin>>n&&n!=0){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) cin>>mat[i][j];
        }
        int numr(0),numc(0),cr,cc,temp;
        for(i=1;i<=n;i++){
            temp=0;
            for(j=1;j<=n;j++) temp+=mat[i][j];
            if(temp%2==1){
                numr++;
                cr=i;
            }
        }
        for(j=1;j<=n;j++){
            temp=0;
            for(i=1;i<=n;i++) temp+=mat[i][j];
            if(temp%2==1){
                numc++;
                cc=j;
            }
        }
        if(numr==0&&numc==0) cout<<"OK"<<endl;
        else if(numr==1&&numc==1) cout<<"Change bit ("<<cr<<","<<cc<<")"<<endl;
        else cout<<"Corrupt"<<endl;
    }
    return 0;
}
        
