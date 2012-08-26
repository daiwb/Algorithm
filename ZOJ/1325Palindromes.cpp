#include <iostream>
#include <string>

using namespace std;

int main(void){
    char a[80];
    while(cin>>a){
        cout<<a;
        int c1(1),c2(1),len,i;
        len=strlen(a);
        for(i=0;i<len/2;i++){
            if(a[i]!=a[len-1-i]){
                c1=0;
                break;
            }
        }
        for(i=0;i<len/2;i++){
            if(a[i]=='A'||a[i]=='H'||a[i]=='I'||a[i]=='M'
            ||a[i]=='O'||a[i]=='T'||a[i]=='U'||a[i]=='V'
            ||a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='1'
            ||a[i]=='8'){
                if(a[len-1-i]!=a[i]){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='E'){
                if(a[len-1-i]!='3'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='J'){
                if(a[len-1-i]!='L'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='L'){
                if(a[len-1-i]!='J'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='S'){
                if(a[len-1-i]!='2'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='Z'){
                if(a[len-1-i]!='5'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='2'){
                if(a[len-1-i]!='S'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='3'){
                if(a[len-1-i]!='E'){
                    c2=0;
                    break;
                }
            }
            else if(a[i]=='5'){
                if(a[len-1-i]!='Z'){
                    c2=0;
                    break;
                }
            }
            else{
                c2=0;
                break;
            }
        }
        if(len%2==1){
            i=len/2;
            if(!(a[i]=='A'||a[i]=='H'||a[i]=='I'||a[i]=='M'
            ||a[i]=='O'||a[i]=='T'||a[i]=='U'||a[i]=='V'
            ||a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='1'
            ||a[i]=='8')) c2=0;
        }
        if(c1==0&&c2==0) cout<<" -- is not a palindrome."<<endl;
        else if(c1==1&&c2==0) cout<<" -- is a regular palindrome."<<endl;
        else if(c1==0&&c2==1) cout<<" -- is a mirrored string."<<endl;
        else cout<<" -- is a mirrored palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}
        
        
