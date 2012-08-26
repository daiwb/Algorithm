/*ZJU 1879 Jolly Jumpers
2003.12.04 By adai
00:00.00 460K*/

#include <iostream>

using namespace std;

int main(void){
    long n,i,sign;
    while(cin>>n){
        long* a=new long[n];
        long* b=new long[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            b[i]=0;
        }
        long temp;
        sign=1;
        for(i=1;i<n;i++){
            temp=a[i]-a[i-1];
            if(temp<0) temp*=-1;
            if(temp==0||temp>n-1||b[temp]==1){
                sign=0;
                break;
            }
            b[temp]=1;
        }
        if(sign==1) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
