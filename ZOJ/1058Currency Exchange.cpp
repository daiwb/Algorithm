#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    int m,n,t,i,j;
    double rate[6][6];
    double money;
    long temp;
    cin>>n;
    for(t=0;t<n;t++){
        if(t) cout<<endl;
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++){
                cin>>rate[i][j];
            }
        }
        while(cin>>m&&m!=0){
            int* a=new int[m];
            for(i=0;i<m;i++) cin>>a[i];
            cin>>money;
            money*=rate[1][a[0]];
            temp=long(money*1000);
            if(temp%10<5) money=(double)(temp/10)/100;
            else money=(double)(temp/10+1)/100;
            for(i=1;i<m;i++){
                money*=rate[a[i-1]][a[i]];
                temp=long(money*1000);
                if(temp%10<5) money=(double)(temp/10)/100;
                else money=(double)(temp/10+1)/100;
            }
            money*=rate[a[m-1]][1];
            temp=long(money*1000);
            if(temp%10<5) money=(double)(temp/10)/100;
            else money=(double)(temp/10+1)/100;
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
            delete []a;
        }
    }
    return 0;
}
            
        
