#include <iostream>
//ZJU 1004 Anagrams by Stack
//2003.08.08 BY ADAI

#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    char in[50],out[50];
    int len,i,j,top,n1,n2,t,size;
    while(cin>>in>>out){
        cout<<"["<<endl;
        if(strlen(in)!=strlen(out)){    
            cout<<"]"<<endl;
            continue;
        }
        len=strlen(in);
        size=(pow(4.0,len)-3*pow(2.0,len)+2)/3+1;
        int* a=new int[len*2];
        char* b=new char[len];
        for(i=0;i<len;i++){
            a[i]=1;
            a[i+len]=0;
        }
        for(i=0;i<size;i++){
            top=n1=n2=t=0;
            for(j=0;j<len*2;j++){
                if(a[j]==1){
                    if(n1==len){
                        t=1;
                        break;
                    }
                    b[top]=in[n1];
                    top++;
                    n1++;
                }
                else{
                    if(top==0){
                        t=1;
                        break;
                    }
                    if(b[top-1]==out[n2]){
                        top--;
                        n2++;
                    }
                    else{
                        t=1;
                        break;
                    }
                }
            }
            if(t==0){
                for(j=0;j<len*2;j++){
                    if(a[j]==1) cout<<"i"<<" ";
                    else cout<<"o"<<" ";
                }
                cout<<endl;
            }
            for(j=len*2-1;j>=0;j--){
                if(a[j]==0) a[j]=1;
                else{
                    a[j]=0;
                    break;
                }
            }
        }
        cout<<"]"<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
                    
                
            
        
    
