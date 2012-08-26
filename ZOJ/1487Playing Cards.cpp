/*00:00.80 444K*/

#include <iostream>

using namespace std;

int main(void){
    int n,m,t,p;
    while(cin>>n>>m){
        int* a=new int[n];
        int i,j=-1,temp;
        temp=n;
        for(i=0;i<n;i++) a[i]=0;
        for(i=1;i<=n;i++){
            p=m%temp;
            for(t=1;t<=p+1;t++){
                j++;
                if(j==n) j=0;
                while(a[j]!=0){
                    j++;
                    if(j==n) j=0;
                }
            }
            temp--;
            a[j]=i;
        }
        cout<<a[0];
        for(i=1;i<n;i++){
            cout<<" "<<a[i];
        }
        cout<<endl;
        delete []a;
    }
    return 0;
}
        
        
