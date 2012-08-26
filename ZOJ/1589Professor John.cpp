//ZJU 1589 Professor John
//2003.08.22 BY ADAI
//MARSHALL ALGORITHM

#include <iostream>

using namespace std;

int main(void){
    int k,kase;
    cin>>k;
    for(kase=1;kase<=k;kase++){
        int a[26][26]={0},b[26][26]={0};
        int m,i,j,k;
        char temp[4];
        cin>>m;
        for(i=0;i<m;i++){
            cin>>temp;
            if(temp[1]=='<') a[temp[0]-'A'][temp[2]-'A']=b[temp[0]-'A'][temp[2]-'A']=1;
            else a[temp[2]-'A'][temp[0]-'A']=b[temp[2]-'A'][temp[0]-'A']=1; 
        }
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                if(a[j][i]==1){
                    for(k=0;k<26;k++){
                        a[j][k]=a[j][k]|a[i][k];
                    }
                }
            }
        }
        cout<<"Case "<<kase<<":"<<endl;
        int judge=0;
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                if(a[i][j]==1&&b[i][j]!=1){
                    cout<<char(i+'A')<<"<"<<char(j+'A')<<endl;
                    judge=1;
                }
            }
        }
        if(judge==0) cout<<"NONE"<<endl;
    }
    return 0;
}
