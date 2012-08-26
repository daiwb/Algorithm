/*ZJU 2060 Fibonacci Again
2003.12.20 By adai
00:00.05 436K*/

#include <iostream>

using namespace std;

int main(void){
    long i;
    while(cin>>i){
        if((i+2)%4==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
