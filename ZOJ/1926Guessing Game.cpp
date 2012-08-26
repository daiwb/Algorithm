/*ZJU 1926 Guessing Game
2003.12.02 By adai
00:00.00 436K*/

#include <iostream>

using namespace std;

int main(void){
    int num[11],n,sign(1),i;
    for(i=1;i<11;i++) num[i]=0;
    char ans[10];
    while(cin>>n&&n!=0){
        cin>>ans;
        cin>>ans;
        if(ans[0]=='h'){
            if(num[n]==1) sign=0;
            num[n]=-1;
        }
        else if(ans[0]=='l'){
            if(num[n]==-1) sign=-1;
            num[n]=1;
        }
        else{
            for(i=1;i<n;i++){
                if(num[i]==-1){
                    sign=0;
                    break;
                }
            }
            if(num[i]!=0) sign=0;
            for(i=n+1;i<=10;i++){
                if(num[i]==1){
                    sign=0;
                    break;
                }
            }
            if(sign==1) cout<<"Stan may be honest"<<endl;
            else cout<<"Stan is dishonest"<<endl;
            for(i=1;i<=10;i++) num[i]=0;
            sign=1;
        }
    }
    return 0;
}
    
