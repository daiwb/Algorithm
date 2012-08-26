//ZJU 1146 LC-Display
//2003.07.31 BY ADAI

#include <iostream>
#include <string>

using namespace std;

int main(void){
    long n,s,i,j,t,len;
    char a[9];
    while(cin>>s>>a){
        if(s==0&&strcmp(a,"0")==0) break;
        len=strlen(a);
        for(i=0;i<len;i++){
            if(a[i]=='0'||a[i]=='2'||a[i]=='3'||a[i]=='5'
            ||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
                cout<<" ";
                for(j=0;j<s;j++) cout<<"-";
                cout<<" ";
            }
            else{
                cout<<" ";
                for(j=0;j<s;j++) cout<<" ";
                cout<<" ";
            }
            if(i<len-1) cout<<" ";
        }
        cout<<endl;
        for(i=0;i<s;i++){
            for(j=0;j<len;j++){
                if(a[j]=='0'||a[j]=='4'||a[j]=='8'||a[j]=='9'){
                    cout<<"|";
                    for(t=0;t<s;t++) cout<<" ";
                    cout<<"|";
                }
                else if(a[j]=='1'||a[j]=='2'||a[j]=='3'||a[j]=='7'){
                    for(t=0;t<s+1;t++) cout<<" ";
                    cout<<"|";
                }
                else{
                    cout<<"|";
                    for(t=0;t<s+1;t++) cout<<" ";
                }
                if(j<len-1) cout<<" ";
            }
            cout<<endl;
        }
        for(i=0;i<len;i++){
            if(a[i]=='0'||a[i]=='1'||a[i]=='7'){
                for(j=0;j<s+2;j++) cout<<" ";
            }
            else{
                cout<<" ";
                for(j=0;j<s;j++) cout<<"-";
                cout<<" ";
            }
            if(i<len-1) cout<<" ";
        }
        cout<<endl;
        for(i=0;i<s;i++){
            for(j=0;j<len;j++){
                if(a[j]=='0'||a[j]=='6'||a[j]=='8'){
                    cout<<"|";
                    for(t=0;t<s;t++) cout<<" ";
                    cout<<"|";
                }
                else if(a[j]=='1'||a[j]=='3'||a[j]=='4'||a[j]=='5'
                ||a[j]=='7'||a[j]=='9'){
                    for(t=0;t<s+1;t++) cout<<" ";
                    cout<<"|";
                }
                else{
                    cout<<"|";
                    for(t=0;t<s+1;t++) cout<<" ";
                }
                if(j<len-1) cout<<" ";
            }
            cout<<endl;
        }
        for(i=0;i<len;i++){
            if(a[i]=='0'||a[i]=='2'||a[i]=='3'||a[i]=='5'
                ||a[i]=='6'||a[i]=='8'||a[i]=='9'){
                cout<<" ";
                for(j=0;j<s;j++) cout<<"-";
                cout<<" ";
            }
            else{
                cout<<" ";
                for(j=0;j<s;j++) cout<<" ";
                cout<<" ";
            }
            if(i<len-1) cout<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}
        
        
