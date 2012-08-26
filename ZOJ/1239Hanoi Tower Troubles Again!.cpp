#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long t,n,i,j,temp;
    cin>>t;
    while(t--){
        cin>>n;
        long* a=new long[n];
        for(i=0;i<n;i++) a[i]=0;
        for(i=1;;i++){
            for(j=0;j<n;j++){
                if(a[j]==0){
                    a[j]=i;
                    break;
                }
                temp=(long)sqrt(0.0+a[j]+i);
                if(a[j]+i==temp*temp){
                    a[j]=i;
                    break;
                }
            }
            if(j==n) break;
        }
        cout<<i-1<<endl;
    }
    return 0;
}
                
        
