/*ZJU 1828 Fibonacci Numbers
2004.01.25 By adai
00:00.07 444K*/

#include <iostream>
using namespace std;

int main(){
    long n,i,j,temp,c;
    int a[1005],b[1005];
    while(cin>>n){
    if(n==1||n==2){
        cout<<1<<endl;
        continue;
    }
    long len(1);
    for(i=0;i<=1003;i++) a[i]=b[i]=0;
    a[1004]=b[1004]=1;
    for(i=3;i<=n;i++){
        c=0;
        for(j=1004;j>=1004-len;j--){
            temp=a[j]+b[j]+c;
            a[j]=b[j];
            if(temp<10){
                b[j]=temp;
                c=0;
            }
            else{
                b[j]=temp-10;
                c=1;
            }
        }
        if(c==1){
            b[1003-len]=1;
            len++;
        }
    }
    i=0;
    while(b[i]==0) i++;
    for(;i<1005;i++) cout<<b[i];
    cout<<endl;
    }
    return 0;
}
        
