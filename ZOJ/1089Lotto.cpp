//ZJU 1089 Lotto
//2003.08.14 BY ADAI

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int k,i,j,t,NeedBlank=0,no;
    while(cin>>k){
        if(k==0) break;
        int* num=new int[k];
        for(i=0;i<k;i++) cin>>num[i];
        if(NeedBlank==1){
            cout<<endl;
        }
        else NeedBlank=1;
        int* a=new int[k];
        for(i=0;i<6;i++) a[i]=0;
        for(;i<k;i++) a[i]=1;
        no=6;
        for(t=0;t<(long)(pow(2,k)-pow(2,k-6)-pow(2,6)+2);t++){
            if(no==6){
                i=0;
                while(a[i]==1) i++;
                cout<<num[i];
                for(i++;i<k;i++){
                    if(a[i]==0) cout<<" "<<num[i];
                }
                cout<<endl;
            }
            for(j=k-1;j>=0;j--){
                if(a[j]==1){
                    a[j]=0;
                    no++;
                }
                else{
                    a[j]=1;   
                    no--;
                    break;
                }
            }
        }
        delete []num;
        delete []a;
    }
    return 0;
}
            
        
