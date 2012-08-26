/*ZJU 2029 The Intervals
2003.12.20 By adai
00:00.00 436K*/

#include <iostream>

using namespace std;

int main(void){
    long n,m,i,j;
    while(cin>>n>>m){
        long* a=new long[n];
        long* b=new long[m];
        for(i=0;i<n;i++) cin>>a[i];
        for(i=0;i<m;i++) cin>>b[i];
        long next;
        for(i=1;i<n;i++){
            next=a[i];
            for(j=i-1;j>=0&&next<a[j];j--) a[j+1]=a[j];
            a[j+1]=next;
        }
        /*
        for(i=1;i<m;i++){
            next=b[i];
            for(j=i-1;j>=0&&next<b[j];j--) b[j+1]=b[j];
            b[j+1]=next;
        }*/
        i=j=0;
        for(;j<m;j++){
            if(b[j]<a[i]) cout<<"no such interval"<<endl;
            else break;
        }
        for(;i<n-1;i++){
            for(;j<m;j++){
                if(b[j]<a[i+1]) cout<<"["<<a[i]<<","<<a[i+1]<<")"<<endl;
                else break;
            }
        }
        for(;j<m;j++) cout<<"no such interval"<<endl;
        cout<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
                
                
