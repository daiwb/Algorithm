#include <iostream>

using namespace std;

int main(void){
    int n,i,count=1;
    while(cin>>n&&n!=0){
        int* a=new int[n];
        long sum(0),num(0);
        for(i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sum/=n;
        for(i=0;i<n;i++){
            if(a[i]-sum>0) num+=a[i]-sum;
        }
        cout<<"Set #"<<count++<<endl;
        cout<<"The minimum number of moves is "<<num<<"."<<endl<<endl;
    }
    return 0;
}
            
