/*ZJU 1715 When Can We Meet?
2003.11.30 By adai
00:00.01 456K*/

#include <iostream>

using namespace std;

int main(void){
    int n,q,i,j,t,temp;
    while(cin>>n>>q&&n!=0){
        int a[50][101]={0};
        for(i=0;i<n;i++){
            cin>>t;
            for(j=0;j<t;j++){
                cin>>temp;
                a[i][temp]=1;    
            }
        }
        int max(0),day(0),num;
        for(i=1;i<=100;i++){
            num=0;
            for(j=0;j<n;j++){
                if(a[j][i]==1) num++;
            }
            if(num>max&&num>=q){
                max=num;
                day=i;
            }
        }
        cout<<day<<endl;
    }
    return 0;
}
            
