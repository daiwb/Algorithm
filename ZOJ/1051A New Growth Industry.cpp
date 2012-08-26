//ZJU 1051 A New Growth Industry
//2003.08.04 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int kase,t,i,j,sum;
    char sign[5]=".!X#";
    cin>>kase;
    for(t=0;t<kase;t++){
        if(t) cout<<endl;
        int day;
        cin>>day;
        int* k=new int[16];
        for(i=0;i<16;i++) cin>>k[i];
        int a[20][20],b[20][20];
        for(i=0;i<20;i++){
            for(j=0;j<20;j++) cin>>a[i][j];
        }
        while(day--){
            for(i=0;i<20;i++){
                for(j=0;j<20;j++){
                    sum=a[i][j];
                    if(i-1>=0) sum+=a[i-1][j];
                    if(i+1<20) sum+=a[i+1][j];
                    if(j-1>=0) sum+=a[i][j-1];
                    if(j+1<20) sum+=a[i][j+1];
                    b[i][j]=a[i][j]+k[sum];
                    if(b[i][j]>3) b[i][j]=3;
                    else if(b[i][j]<0) b[i][j]=0;
                }
            }
            for(i=0;i<20;i++){
                for(j=0;j<20;j++) a[i][j]=b[i][j];
            }
        }
        for(i=0;i<20;i++){
            for(j=0;j<20;j++) cout<<sign[a[i][j]];
            cout<<endl;
        }
        delete []k;
    }
    return 0;
}
                
        
                    
