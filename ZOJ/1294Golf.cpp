//ZJU 1294 Golf
//2003.08.18 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int kase=1;  //p--the par for the hole 
    int p,s;     //s--the number of strokes John needed that that hole
    while(cin>>p>>s&&!(p==0&&s==0)){
        cout<<"Hole #"<<kase++<<endl;
        if(s==1){
            cout<<"Hole-in-one."<<endl<<endl;
            continue;
        }
        if(s-p>=2) cout<<"Double Bogey."<<endl<<endl;
        else if(s-p==1) cout<<"Bogey."<<endl<<endl;
        else if(s-p==0) cout<<"Par."<<endl<<endl;
        else if(p-s==1) cout<<"Birdie."<<endl<<endl;
        else if(p-s==2) cout<<"Eagle."<<endl<<endl;
        else cout<<"Double Eagle."<<endl<<endl;
    }
    return 0;
}
