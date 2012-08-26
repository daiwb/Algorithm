/*ZJU 1698 Easier Done Than Said?
2003.11.30 By adai
00:00.00 436K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char pwd[21];
    int a[26]={0};
    a[0]=a[4]=a[8]=a[14]=a[20]=1;
    while(cin>>pwd){
        if(strcmp(pwd,"end")==0) break;
        int len=strlen(pwd),i,num(1),sign;
        if(a[pwd[0]-'a']==1) sign=1;
        else sign=0;
        for(i=1;i<len;i++){
            if(a[pwd[i]-'a']==1) sign=1;
            if(pwd[i]==pwd[i-1]){
                if(pwd[i]!='e'&&pwd[i]!='o'){
                    sign=0;
                    break;
                }
            }
            if(a[pwd[i]-'a']==a[pwd[i-1]-'a']){
                num++;
                if(num>=3){
                    sign=0;
                    break;
                }
            }
            else num=1;
        }
        if(sign==0) cout<<"<"<<pwd<<"> is not acceptable."<<endl;
        else cout<<"<"<<pwd<<"> is acceptable."<<endl;
    }
    return 0;
}
            
        
    
