//ZJU 1629 Counting Triangles
//2003.07.28 by adai

#include <iostream>

using namespace std;

int main(void){
    long n,num1,num2;
    while(cin>>n){
        num1=n*(n+1)*(n+2)/6;
        if(n%2==1) num2=(2*n*n*n+3*n*n-2*n-3)/24;
        else num2=(2*n*n*n+3*n*n-2*n)/24;
        cout<<num1+num2<<endl;
    }
    return 0;
}
            
        
