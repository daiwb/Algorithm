//ZJU 1099 HTML
//2003.08.13 BY ADAI

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char c[85];
    int len,clen,i;
    len=0;
    while(cin>>c){
        if(strcmp(c,"<br>")==0){
            cout<<endl;
            len=0;
        }
        else if(strcmp(c,"<hr>")==0){
            if(len>0) cout<<endl;
            for(i=0;i<80;i++) cout<<"-";
            cout<<endl;
            len=0;
        }
        else{
            clen=strlen(c);
            if(len==0){
                cout<<c;
                len=clen;
            }
            else{
                if(len+1+clen<=80){
                    cout<<" "<<c;
                    len+=1+clen;
                }
                else{
                    cout<<endl<<c;
                    len=clen;
                }
            }
        }
    }
    cout<<endl;
    return 0;
}
        
        
    
