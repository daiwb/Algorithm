/*ZJU 1928 Combination Lock
2003.12.02 By adai
00:00.01 436K*/

#include <iostream>

using namespace std;

int main(void){
    int dial,num[3];
    while(cin>>dial>>num[0]>>num[1]>>num[2]){
        if(dial==0&&num[0]==0&&num[1]==0&&num[2]==0) break;
        long deg=720;
        deg+=(dial+40-num[0])%40*9;
        deg+=360;
        if(num[0]==num[1]) deg+=360;
        else deg+=(num[1]+40-num[0])%40*9;
        if(num[1]==num[2]) deg+=360;
        else deg+=(num[1]+40-num[2])%40*9;
        cout<<deg<<endl;
    }
    return 0;
}
