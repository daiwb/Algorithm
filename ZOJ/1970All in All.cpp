/*ZJU 1970 All in All
2003.12.04 By adai
00:00.01 632K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char a[100000],b[100000];
    while(cin>>a>>b){
        long sign,i,j,lena,lenb,temp;
        lena=strlen(a);
        lenb=strlen(b);
        sign=1;
        j=0;
        for(i=0;i<lena;i++){
            temp=0;
            for(;j<lenb;j++){
                if(a[i]==b[j]){
                    temp=1;
                    j++;
                    break;
                }
            }
            sign=sign*temp;
            if(sign==0) break;
        }
        if(sign==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
                    
        


