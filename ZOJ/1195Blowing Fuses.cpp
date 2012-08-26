//ZJU 1195 Blowing Fuses
//2003.08.15 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    long i,current,max,IsBlown,kase=1;
    long n,m,c;//n:number of devices m:number of operations c:capacity
    while(cin>>n>>m>>c&&!(n==0&&m==0&&c==0)){
        long* capcity=new long[n+1];
        long* status=new long[n+1];
        for(i=1;i<=n;i++){
            cin>>capcity[i];
            status[i]=0;
        }
        long* operation=new long[m];
        for(i=0;i<m;i++) cin>>operation[i];
        IsBlown=current=max=0;
        for(i=0;i<m;i++){
            if(status[operation[i]]==0){
                current+=capcity[operation[i]];
                if(current>c){
                    IsBlown=1;
                    break;
                }
                if(current>max) max=current;
                status[operation[i]]=1;
            }
            else{
                current-=capcity[operation[i]];
                status[operation[i]]=0;
            }
        }
        cout<<"Sequence "<<kase++<<endl;
        if(IsBlown==1) cout<<"Fuse was blown."<<endl;
        else{
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<max<<" amperes."<<endl;
        }
        cout<<endl;
        delete []capcity;
        delete []status;
        delete []operation;
    }
    return 0;
}

            
            
            
        
        
        
