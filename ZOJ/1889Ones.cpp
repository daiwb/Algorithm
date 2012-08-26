/*ZJU 1889 Ones
2003.12.03 By adai
00:00.36 4348K*/

#include <iostream>

using namespace std;

int main(void){
    long n;
    while(cin>>n){
        long num(1),i(1),j(1);
        while(i%n!=0){
            num++;
            j=(j*10)%n;
            i=(i+j)%n;
        }
        cout<<num<<endl;
    }
    return 0;
}
        
