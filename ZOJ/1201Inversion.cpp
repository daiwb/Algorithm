#include <iostream>

using namespace std;

int main(void){
    int n;
    while(cin>>n&&n!=0){
        int* a=new int[n+1];
        int* b=new int[n+1];
        int i,j,num,t;
        char ch;
        cin>>ch;
        for(i=1;i<=n;i++) cin>>a[i];
        if(ch=='P'){
            for(i=1;i<=n;i++){
                num=0;
                for(j=1;j<i;j++){
                    if(a[j]>a[i]) num++;
                }
                b[a[i]]=num;
            }
            cout<<b[1];
            for(i=2;i<=n;i++) cout<<" "<<b[i];
            cout<<endl;
        }
        else if(ch=='I'){
            for(i=1;i<=n;i++) b[i]=0;
            for(i=1;i<=n;i++){
                t=0;
                for(j=1;;j++){
                    if(b[j]==0) t++;
                    if(t==a[i]+1) break;
                }
                b[j]=i;
            }
            cout<<b[1];
            for(i=2;i<=n;i++) cout<<" "<<b[i];
            cout<<endl;
        }
    }
    return 0;
}
                
                
                
        
